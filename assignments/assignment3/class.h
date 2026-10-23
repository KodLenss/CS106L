#pragma once

#include <string>
#include <utility>

class obj {
private:
    long long id = 0;
    std::string name = "default";

    static long long counter;

public:

    obj(): id(counter++){};
    obj(std::string name): id(counter++), name(name){}

    long long getId() const;
    std::string getName() const;
    void setName(const std::string& name);

    obj& operator=(const obj& other);
    obj(const obj& other) : id(counter++), name(other.name) {}

    virtual std::string attrib() const;
    virtual ~obj() = default;

};

class point : public obj {
private:

public:
    double x = 0.0;
    double y = 0.0;

    point();
    point(double x, double y);
    
    std::string attrib() const override;

    point& operator=(const point& other) = default;

    virtual ~point() = default;
};

class point3d : public point {
public:
    double z = 0.0;

    point3d();
    point3d(double x, double y, double z);

    std::string attrib() const override;

    point3d& operator=(const point3d& other) = default;

    ~point3d() override = default;
};

template <typename T>
class line_seg : public obj {
private:

public:
    std::pair<T, T> endpoints;

    line_seg();
    line_seg(const T& p1, const T& p2);

    line_seg& operator=(const line_seg& other) = default;

    double length() const;

    std::string attrib() const override;

    ~line_seg() = default;
};