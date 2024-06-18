#include <stdio.h>
#include "btstack.h"
#include "pico/cyw43_arch.h"
#include "pico/btstack_cyw43.h"
#include "pico/stdlib.h"

#include "picow_ble.h"

/*
 * @section Advertisements 
 *
 * @text The Flags attribute in the Advertisement Data indicates if a device is dual-mode or le-only.
 */
/* LISTING_START(advertisements): Advertisement data: Flag 0x02 indicates dual-mode device */
// 广播数据格式： length , type, data
const uint8_t adv_data[] = {
    // Flags general discoverable
    0x02, BLUETOOTH_DATA_TYPE_FLAGS, 0x02,
    // Name
    0x0a, BLUETOOTH_DATA_TYPE_COMPLETE_LOCAL_NAME, 'P', 'i', 'c', 'o', 'W', '-', 'B', 'L', 'E',
    // Incomplete List of 16-bit Service Class UUIDs 
    0x03, BLUETOOTH_DATA_TYPE_INCOMPLETE_LIST_OF_16_BIT_SERVICE_CLASS_UUIDS, 0xbb, 0xaa,
};
/* LISTING_END */
uint8_t adv_data_len = sizeof(adv_data);

static btstack_timer_source_t heartbeat;
static btstack_packet_callback_registration_t hci_event_callback_registration;

// 蓝牙堆栈事件回调
static void packet_handler(uint8_t packet_type, uint16_t channel, uint8_t *packet, uint16_t size) {

    UNUSED(size);
    UNUSED(channel);
    bd_addr_t local_addr;
    if (packet_type != HCI_EVENT_PACKET)
        return;

    uint8_t event_type = hci_event_packet_get_type(packet);
    printf("event_type: %d\n", event_type);
    switch (event_type)
    {
    case BTSTACK_EVENT_STATE:
        if (btstack_event_state_get_state(packet) != HCI_STATE_WORKING)
            return;
        gap_local_bd_addr(local_addr);
        printf("BTstack up and running on %s.\n", bd_addr_to_str(local_addr));

        // 设置广播数据
        uint16_t adv_int_min = 800;
        uint16_t adv_int_max = 800;
        uint8_t adv_type = 0;
        bd_addr_t null_addr;
        memset(null_addr, 0, 6);
        gap_advertisements_set_params(adv_int_min, adv_int_max, adv_type, 0, null_addr, 0x07, 0x00);
        assert(adv_data_len <= 31); // ble limitation
        gap_advertisements_set_data(adv_data_len, (uint8_t *)adv_data);
        // 开始广播
        gap_advertisements_enable(1);
        break;
    case HCI_EVENT_DISCONNECTION_COMPLETE:
        break;
    case ATT_EVENT_CAN_SEND_NOW:
        break;
    case ATT_WRITE_REQUEST:

        break;
    case ATT_WRITE_COMMAND:
        printf("ATT_WRITE_COMMAND\n");
        break;
    case GATT_WRITE_VALUE_OF_CHARACTERISTIC_WITHOUT_RESPONSE:
        printf("GATT_WRITE_VALUE_OF_CHARACTERISTIC_WITHOUT_RESPONSE\n");
        break;
    case HCI_EVENT_TRANSPORT_PACKET_SENT:
        printf("HCI_EVENT_TRANSPORT_PACKET_SENT\n");
        break;
    default:
        break;
    }
}

uint16_t att_read_callback(hci_con_handle_t connection_handle, uint16_t att_handle, uint16_t offset, uint8_t * buffer, uint16_t buffer_size) {
    UNUSED(connection_handle);
    printf("Read callback for handle 0x%04x\n", att_handle);

    return 0;
}

int att_write_callback(hci_con_handle_t connection_handle, uint16_t att_handle, uint16_t transaction_mode, uint16_t offset, uint8_t *buffer, uint16_t buffer_size) {
    UNUSED(transaction_mode);
    UNUSED(offset);
    UNUSED(buffer_size);
    
     printf("att_write_callback\n");

    // 读取客户端写入的数据

    printf("Handle: 0x%04X\n", att_handle);
    printf("Data: ");
    for (int i = 0; i < buffer_size; i++)
    {
        printf("%02X ", buffer[i]);
    }
    printf("\n");
    return 0;
}

int main() {
    // 初始化标准输入输出
    stdio_init_all();

    // initialize CYW43 driver architecture (will enable BT if/because CYW43_ENABLE_BLUETOOTH == 1)
    if (cyw43_arch_init()) {
        printf("failed to initialise cyw43_arch\n");
        return -1;
    }

    // 初始化 BTStack
    l2cap_init();
    sm_init();

    att_server_init(profile_data, att_read_callback, att_write_callback);    

    // inform about BTstack state
    hci_event_callback_registration.callback = &packet_handler;
    hci_add_event_handler(&hci_event_callback_registration);

    // register for ATT event
    att_server_register_packet_handler(packet_handler);

    // 打开蓝牙
    hci_power_control(HCI_POWER_ON);

    // 进入主循环
    while (true)
    {
        // sleep_ms(1000);
    }

    return 0;
}
