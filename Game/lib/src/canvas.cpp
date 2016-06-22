/*
 * Implementation of the class that represents the area of the window to be drawn.
 * Licença: LGPL. Sem copyright.
 */

#include "core/canvas.hpp"

#include "core/point.hpp"
#include "core/line.hpp"
#include "core/rect.hpp"
#include "core/circle.hpp"
#include "core/texture.hpp"
#include "core/font.hpp"
#include "core/bitmap.hpp"
#include "core/environment.hpp"

#include <cassert>

/**
 * @brief [brief description]
 * 
 * @param renderer 
 * @param width variable that stores the width of the resolution.
 * @param height variable that stores the height of the resolution.
 */
Canvas::Canvas(SDL_Renderer *renderer, const int width, const int height)
    
{
    m_renderer = renderer;
    m_width = width;
    m_height = height;
    m_blend_mode = NONE;

    set_color(Color::WHITE);

    m_bitmap = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
    m_texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
                                  SDL_TEXTUREACCESS_STREAMING, width, height);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param e [description]
 * @return [description]
 */
Canvas::~Canvas()
{
    SDL_FreeSurface(m_bitmap);
    SDL_DestroyTexture(m_texture);
}

int Canvas::width() const
{
    return m_width;
}

int Canvas::height() const
{
    return m_height;
}

const Color& Canvas::color() const
{
    return m_color;
}

shared_ptr<Font> Canvas::font() const
{
    return m_font;
}

Canvas::BlendMode Canvas::blend_mode() const
{
    return m_blend_mode;
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param color [description]
 */
void Canvas::set_color(const Color& color)
{
    m_color = color;
    SDL_SetRenderDrawColor(m_renderer, color.r(), color.g(), color.b(), color.a());
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param width [description]
 * @param height [description]
 */
void Canvas::set_resolution(int width, int height)
{
    if (m_bitmap)
    {
        SDL_FreeSurface(m_bitmap);
    }

    if (m_texture)
    {
        SDL_DestroyTexture(m_texture);
    }

    m_bitmap = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
    m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_ARGB8888,
                                  SDL_TEXTUREACCESS_STREAMING, width, height);

    m_width = width;
    m_height = height;
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param font [description]
 */
void Canvas::set_font(shared_ptr<Font>& font)
{
    m_font = font;
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param mode [description]
 */
void Canvas::set_blend_mode(BlendMode mode)
{
    switch (mode)
    {
    case NONE:
        SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_NONE);
        break;

    case BLEND:
        SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);
        break;
    }

    m_blend_mode = mode;
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param color [description]
 */
void Canvas::clear(const Color& color)
{
    if (color != m_color)
    {
        set_color(color);
    }

    SDL_RenderClear(m_renderer);
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param t [description]
 */
void Canvas::update()
{
    SDL_RenderPresent(m_renderer);
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param point [description]
 */
void Canvas::draw(const Point& point) const
{
    //It is an object of the class environment. Is a pointer to the current instance of the game environment.
    Environment *env = Environment::get_instance();
    assert((env != NULL) && "env to pick up the instance of environment");

    int horizontal_position = point.horizontal_position() - env->camera->horizontal_position();
    int vertical_position = point.vertical_position() - env->camera->vertical_position();

    SDL_RenderDrawPoint(m_renderer, horizontal_position, vertical_position);
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param point [description]
 * @param color [description]
 */
void Canvas::draw(const Point& point, const Color& color)
{
    if (color != m_color)
    {
        set_color(color);
    }

    draw(point);
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param line [description]
 */
void Canvas::draw(const Line& line) const
{
    //It is an object of the class environment. Is a pointer to the current instance of the game environment.
    Environment *env = Environment::get_instance();
    assert((env != NULL) && "env to pick up the instance of environment");

    int horizontal_position_a = line.a().horizontal_position() - env->camera->horizontal_position();
    int vertical_position_a = line.a().vertical_position() - env->camera->vertical_position();
    int horizontal_position_b = line.b().horizontal_position() - env->camera->horizontal_position();
    int vertical_position_b = line.b().vertical_position() - env->camera->vertical_position();

    SDL_RenderDrawLine(m_renderer, horizontal_position_a, vertical_position_a, horizontal_position_b, vertical_position_b);
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param line [description]
 * @param color [description]
 */
void Canvas::draw(const Line& line, const Color& color)
{
    if (color != m_color)
    {
        set_color(color);
    }

    draw(line);
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param rect [description]
 */
void Canvas::draw(const Rect& rect) const
{
    //It is an object of the class environment. Is a pointer to the current instance of the game environment.
    Environment *env = Environment::get_instance();
    assert((env != NULL) && "env to pick up the instance of environment");

    int horizontal_position = rect.horizontal_position() - env->camera->horizontal_position();
    int vertical_position = rect.vertical_position() - env->camera->vertical_position();

    SDL_Rect rectangle;
    rectangle.x = horizontal_position;
    rectangle.y = vertical_position;
    rectangle.w = rect.width();
    rectangle.h = rect.height();

    SDL_RenderDrawRect(m_renderer, &rectangle);
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param rect [description]
 * @param color [description]
 */
void Canvas::draw(const Rect& rect, const Color& color)
{
    if (color != m_color)
    {
        set_color(color);
    }

    draw(rect);
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param rect [description]
 */
void Canvas::fill(const Rect& rect) const
{
    //It is an object of the class environment. Is a pointer to the current instance of the game environment.
    Environment *env = Environment::get_instance();
    assert((env != NULL) && "env to pick up the instance of environment");

    SDL_Rect rectangle;
    rectangle.x = rect.horizontal_position() - env->camera->horizontal_position();
    rectangle.y = rect.vertical_position() - env->camera->vertical_position();
    rectangle.w = rect.width();
    rectangle.h = rect.height();

    SDL_RenderFillRect(m_renderer, &rectangle);
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param rect [description]
 * @param color [description]
 */
void Canvas::fill(const Rect& rect, const Color& color)
{
    if (color != m_color)
    {
        set_color(color);
    }

    fill(rect);
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param circle [description]
 */
void Canvas::draw(const Circle& circle) const
{
    //It is an object of the class environment. Is a pointer to the current instance of the game environment.
    Environment *env = Environment::get_instance();
    assert((env != NULL) && "object to pick up the instance of environment");

    int circle_horizontal_position = circle.center().horizontal_position() - env->camera->horizontal_position();
    int circle_vertical_position = circle.center().vertical_position() - env->camera->vertical_position();

    int radius = circle.radius();

    int error = 3 - (radius << 1);
    int i = 0;
    int j = radius;

    do
    {
        draw_circle_points(circle_horizontal_position, circle_vertical_position, i, j);

        if (error < 0)
        {
            error += (i << 2) + 6;
        }
        else
        {
            error += ((i - j) << 2) + 10;
            j--;
        }

        i++;
    } while (i <= j);
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param circle [description]
 */
void Canvas::fill(const Circle& circle) const
{
     //It is an object of the class environment. Is a pointer to the current instance of the game environment.
    Environment *env = Environment::get_instance();
    assert((env != NULL) && "env to pick up the instance of environment");

    int circle_horizontal_position = circle.center().horizontal_position() - env->camera->horizontal_position();
    int circle_vertical_position = circle.center().vertical_position() - env->camera->vertical_position();
    int radius = circle.radius();

    int error = 3 - (radius << 1);
    int i = 0, j = radius;

    do
    {
        fill_circle_points(circle_horizontal_position, circle_vertical_position, i, j);

        if (error < 0)
        {
            error += (i << 2) + 6;
        }
        else
        {
            error += ((i - j) << 2) + 10;
            j--;
        }

        i++;
    } while (i <= j);
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param circle [description]
 * @param color [description]
 */
void Canvas::fill(const Circle& circle, const Color& color)
{
    if (color != m_color)
    {
        set_color(color);
    }

    fill(circle);
}


void Canvas::draw(const Circle& circle, const Color& color)
{
    if (color != m_color)
    {
        set_color(color);
    }

    draw(circle);
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param circle_horizontal_position [description]
 * @param circle_vertical_position [description]
 * @param horizontal_position [description]
 * @param vertical_position [description]
 */
void Canvas::draw_circle_points(int circle_horizontal_position, int circle_vertical_position, int horizontal_position, int vertical_position) const
{
    SDL_Point points[]
    {
        {circle_horizontal_position + horizontal_position, circle_vertical_position + vertical_position},
         {circle_horizontal_position + horizontal_position, circle_vertical_position - vertical_position}, 
         {circle_horizontal_position + vertical_position, circle_vertical_position + horizontal_position}, 
         {circle_horizontal_position + vertical_position, circle_vertical_position - horizontal_position},
        {circle_horizontal_position - horizontal_position, circle_vertical_position + vertical_position}, 
        {circle_horizontal_position - horizontal_position, circle_vertical_position - vertical_position}, 
        {circle_horizontal_position - vertical_position, circle_vertical_position + horizontal_position}, 
        {circle_horizontal_position - vertical_position, circle_vertical_position - horizontal_position}
    };

    SDL_RenderDrawPoints(m_renderer, points, 8);
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param circle_horizontal_position [description]
 * @param circle_vertical_position [description]
 * @param horizontal_position [description]
 * @param vertical_position [description]
 */
void Canvas::fill_circle_points(int circle_horizontal_position, 
                                            int circle_vertical_position, 
                                            int horizontal_position, 
                                            int vertical_position) const
{
    draw(Line(Point(circle_horizontal_position + horizontal_position, 
                            circle_vertical_position + vertical_position), 
                            Point(circle_horizontal_position + horizontal_position, 
                                circle_vertical_position - vertical_position)));

    draw(Line(Point(circle_horizontal_position - horizontal_position, 
                            circle_vertical_position + vertical_position), 
                            Point(circle_horizontal_position - horizontal_position, 
                                circle_vertical_position - vertical_position)));

    draw(Line(Point(circle_horizontal_position + vertical_position, 
                            circle_vertical_position + horizontal_position), 
                            Point(circle_horizontal_position + vertical_position, 
                                circle_vertical_position - horizontal_position)));

    draw(Line(Point(circle_horizontal_position - vertical_position, 
                            circle_vertical_position + horizontal_position), 
                            Point(circle_horizontal_position - vertical_position, 
                                circle_vertical_position - horizontal_position)));
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param texture [description]
 * @param horizontal_position [description]
 * @param vertical_position [description]
 */
void Canvas::draw(const Texture *texture, double horizontal_position, double vertical_position) const
{
    if (not texture)
    {
        return;
    }

    Rect clip { 0, 0, (double) texture->size().first, (double) texture->size().second };

    draw(texture, clip, horizontal_position, vertical_position);
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param texture [description]
 * @param clip [description]
 * @param horizontal_position [description]
 * @param vertical_position [description]
 * @param width [description]
 * @param height [description]
 */
void Canvas::draw(const Texture *texture, Rect clip, double horizontal_position, double vertical_position, double width, double height) const
{
    //It is an object of the class environment. Is a pointer to the current instance of the game environment.
    Environment *env = Environment::get_instance();
    assert((env != NULL) && "env to pick up the instance of environment");


    int original_horizontal_position = (int) clip.horizontal_position();
    int original_vertical_position = (int) clip.vertical_position();
    int original_width = (int) clip.width();
    int original_height = (int) clip.height();

    int destination_horizontal_position = (int) horizontal_position - env->camera->horizontal_position();
    int destination_vertical_position = (int) vertical_position - env->camera->vertical_position();

    int destination_width = ((int) width );

    if (width==0)
    {
        destination_width = ((int) texture->width());
    }else
    {
        // Nothing to do.
    }

    int destination_height = ((int) height );
    if (height==0)
    {
        destination_height = ((int) texture->height());
    }else
    {
        // Nothing to do.
    }

    SDL_Rect orig { original_horizontal_position, original_vertical_position, original_width, original_height };
    SDL_Rect dest { destination_horizontal_position, destination_vertical_position, destination_width, destination_height };

    SDL_Texture *image = static_cast<SDL_Texture *>(texture->data());
    assert((image != NULL) && "image to pick up the instance of environment");

    SDL_RenderCopy(m_renderer, image, &orig, &dest);
}

SDL_Renderer * Canvas::renderer() const
{
    return m_renderer;
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param text [description]
 * @param horizontal_position [description]
 * @param vertical_position [description]
 * @param color [description]
 */
void Canvas::draw(const string& text, double horizontal_position, double vertical_position, const Color& color) const
{
    if (not m_font.get())
    {
        return;
    }

    SDL_Color text_color { color.r(), color.g(), color.b(), color.a() };

    SDL_Surface *surface = TTF_RenderUTF8_Blended(m_font->font(), text.c_str(),
                                                  text_color);

    if (not surface)
    {
        return;
    }

    int width = surface->w;
    int height = surface->h;

    SDL_Texture *texture = SDL_CreateTextureFromSurface(m_renderer, surface);
    assert((texture != NULL) && "texture to pick up the instance of environment");

    SDL_FreeSurface(surface);

    if (not texture)
    {
        return;
    }


    Environment *env = Environment::get_instance();
    assert((env != NULL) && "env to pick up the instance of environment");

    int destination_x = (int) horizontal_position - env->camera->horizontal_position();
    int destination_y = (int) vertical_position - env->camera->vertical_position();

    SDL_Rect dest { destination_x, destination_y, width, height };

    SDL_RenderCopy(m_renderer, texture, NULL, &dest);

    SDL_DestroyTexture(texture);
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param text [description]
 * @param color [description]
 * 
 * @return [description]
 */
Texture * Canvas::render_text(const string& text, const Color& color)
{
    if (not m_font.get())
    {
        return nullptr;
    }

    SDL_Color text_color { color.r(), color.g(), color.b(), color.a() };
    SDL_Surface *surface = TTF_RenderUTF8_Blended(m_font->font(),
            text.c_str(), text_color);

    if (not surface)
    {
        return nullptr;
    }

    int width = surface->w;
    int height = surface->h;

    SDL_Texture *texture = SDL_CreateTextureFromSurface(m_renderer, surface);
    assert((texture != NULL) && "texture to pick up the instance of environment");

    SDL_FreeSurface(surface);

    if (not texture)
    {
        return nullptr;
    }

    if (color.a() != 255)
    {
        SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    }

    return new Texture(texture, width, height);
}

SDL_Surface * Canvas::bitmap() const
{
    return m_bitmap;
}
/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param bitmap [description]
 * @param e [description]
 * @param e [description]
 */
void Canvas::draw(const Bitmap *bitmap, double, double) const
{
    SDL_UpdateTexture(this->m_texture, NULL, bitmap->pixels(), this->m_width * sizeof(Uint32));
    SDL_RenderCopy(this->m_renderer, this->m_texture, NULL, NULL);
}
