#include " Pool.h"

class YourGameObject {
public:
    YourGameObject() : active(false) {}

    void SetActive(bool state) {
        active = state;
    }

    bool IsActive() const {
        return active;
    }

private:
    bool active;
};


// Pool<YourGameObject> gameObjectPool(10);


