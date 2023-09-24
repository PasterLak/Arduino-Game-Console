

 class GameObject
{
    private:
    bool _isActive = true;
    public:
    
    virtual void update() = 0;
    virtual void draw() = 0;

    bool isActive() const {return _isActive;}
    void setActive(bool state) { _isActive = state;}
};