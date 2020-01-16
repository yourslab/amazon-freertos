/* FreeRTOS includes. */

#include <string.h>

#include "FreeRTOS.h"
#include "queue.h"
#include "iot_ble.h"

BLEServiceListElement_t* allocator_BLEServiceListElement_t()
{
    BLEServiceListElement_t* pServiceElement =  pvPortMalloc(sizeof(BLEServiceListElement_t));
    pServiceElement->pService = pvPortMalloc(sizeof(BTService_t));

    pServiceElement->pEventsCallbacks = pvPortmalloc(sizeof(IotBleAttributeEventCallback_t));
    pServiceElement->pEventsCallbacks[0] = eventCallbackStub;
    return pServiceElement;
}

void eventCallbackStub(IotBleAttributeEvent_t* pParam)
{
}

extern _bleInterface_t _BTInterface;

void addBleService()
{
    pServiceElement = allocator_BLEServiceListElement_t();
    IotListDouble_InsertHead(&_BTInterface.serviceListHead, &pServiceElement->serviceList);
}
void harness() {

    uint16_t connId;
    uint32_t transId;
    BTBdaddr_t deviceAddress;
    uint16_t attrHandle;
    uint8_t* value = malloc(10);
    size_t length;
    uint16_t offset;
    bool needRsp = false;
    bool isPrep = false;

    addBleService();

    _requestWriteCb( connId,
        transId,
        &deviceAddress,
        attrHandle,
        offset,
        length,
        needRsp,
        isPrep,
        ( uint8_t * ) value );
}

