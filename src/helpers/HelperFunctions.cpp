#include "HelperFunctions.h"

void CHECK_RETURN_CODE(ReturnCode rc)
{
    switch (rc)
    {
    case ReturnCode::Success:
        break;
    case ReturnCode::Failure:
        printf("FAILURE RETURN CODE");
        break;
    default:
        printf("FAILURE RETURN CODE");
        break;
    }
}