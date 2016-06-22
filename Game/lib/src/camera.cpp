/*
 * Implementação da classe Camera.
 *
 * Autor: Edson Alves
 * Data: 27/05/2015
 * Licença: LGPL. Sem copyright.
 */
#include "core/camera.hpp"
#include "core/rect.hpp"

#include <iostream>
using namespace std;

class Camera::Impl
{
public:
    Impl(Camera *camera, Mode mode)
        : m_camera(camera), m_mode(mode), m_target(nullptr),
        m_limits(-1000000, -1000000, 2000000, 2000000) {}

    Mode mode() const { return m_mode; }
    void set_mode(Mode mode) { m_mode = mode; }

    void follow(const Object *target) { m_target = target; }

    void update_self(unsigned long)
    {
        if (m_mode == Camera::FOLLOWING and m_target)
        {
            double horizontal_position = m_target->horizontal_position() + (m_target->width() - m_camera->width())/2;
            double vertical_position = m_target->vertical_position() + (m_target->height() - m_camera->height())/2;

            if (horizontal_position < m_limits.horizontal_position())
            {
                horizontal_position = m_limits.horizontal_position();
            }

            if (horizontal_position + m_camera->width() > m_limits.horizontal_position() + m_limits.width())
            {
                horizontal_position = m_limits.horizontal_position() + m_limits.width() - m_camera->width();
            }

            if (vertical_position < m_limits.vertical_position())
            {
                vertical_position = m_limits.vertical_position();
            }

            if (vertical_position + m_camera->height() > m_limits.vertical_position() + m_limits.height())
            {
                vertical_position = m_limits.vertical_position() + m_limits.height() - m_camera->height();
            }

            m_camera->set_position(horizontal_position, vertical_position);
        }
    }

    void draw_self() {}

    void set_limits(const Rect& limits)
    {
        m_limits = limits;
    }

private:
    Camera *m_camera;
    Mode m_mode;
    const Object *m_target;
    Rect m_limits;
};

Camera::Camera(double horizontal_position, double vertical_position, double width, double height, Mode mode)
    : Object(nullptr, "", horizontal_position, vertical_position, width, height), m_impl(new Camera::Impl(this, mode))
{
}

Camera::~Camera()
{
}

Camera::Mode
Camera::mode() const
{
    return m_impl->mode();
}

void
Camera::set_mode(Mode mode)
{
    m_impl->set_mode(mode);
}

void
Camera::update_self(unsigned long elapsed)
{
    m_impl->update_self(elapsed);
}

void
Camera::draw_self()
{
    m_impl->draw_self();
}

void
Camera::follow(const Object* object)
{
    m_impl->follow(object);
}

void
Camera::set_limits(const Rect& limits)
{
    m_impl->set_limits(limits);
}
