#include "myclass.h"

void MyClass::cppSlot(const QVariant &msg) {
    qWarning() << "Called the C++ slot with message:" << msg.toString();
}
