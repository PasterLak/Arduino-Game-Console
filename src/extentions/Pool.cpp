#include "extentions/ Pool.h"

class YourGameObject {
public:
    YourGameObject() : active(false) {}

    void SetActive(bool state) {
        active = state;
    }

    bool IsActive() const {
        return active;
    }

    // Добавьте здесь методы и свойства, специфичные для вашего игрового объекта
    // Например, конструктор, инициализирующий ваш объект.

private:
    bool active;
};

// Добавьте здесь определения методов и свойств вашего игрового объекта, если необходимо

// Пример использования пула:
// Pool<YourGameObject> gameObjectPool(10); // Создайте пул объектов вашего игрового класса


