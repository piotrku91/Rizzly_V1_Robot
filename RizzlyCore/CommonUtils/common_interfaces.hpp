#pragma once

class Initable {
    protected:
    bool init_ok_{false};

    public:
    virtual void init() = 0;
    virtual void deinit() = 0;
};