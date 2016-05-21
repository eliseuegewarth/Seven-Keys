/*
 * Implementação da classe que representa a área da janela a ser desenhada.
 *
 * Autor: Edson Alves
 * Data: 13/04/2015
 * Licença: LGPL. Sem copyright.
 */
#include "core/canvas.h"

#include "core/point.h"
#include "core/line.h"
#include "core/rect.h"
#include "core/circle.h"
#include "core/texture.h"
#include "core/font.h"
#include "core/bitmap.h"
#include "core/environment.h"

Canvas::Canvas(SDL_Renderer *renderer, int width, int height)
    : m_renderer(renderer), m_width(width), m_height(height), m_blend_mode(NONE)
{
    set_color(Color::WHITE);
    m_bitmap = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
    m_texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING, width, height);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");
}

Canvas::~Canvas()
{
    SDL_FreeSurface(m_bitmap);
    SDL_DestroyTexture(m_texture);
}

int
Canvas::width() const
{
    return m_width;
}

int
Canvas::height() const
{
    return m_height;
}

const Color&
Canvas::color() const
{
    return m_color;
}

shared_ptr<Font>
Canvas::font() const
{
    return m_font;
}

Canvas::BlendMode
Canvas::blend_mode() const
{
    return m_blend_mode;
}

void
Canvas::set_color(const Color& color)
{
    m_color = color;
    SDL_SetRenderDrawColor(m_renderer, color.r(), color.g(), color.b(), color.a());
}

void
Canvas::set_resolution(int width, int height)
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

void
Canvas::set_font(shared_ptr<Font>& font)
{
    m_font = font;
}

void
Canvas::set_blend_mode(BlendMode mode)
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

void
Canvas::clear(const Color& color)
{
    if (color != m_color)
    {
        set_color(color);
    }

    SDL_RenderClear(m_renderer);
}

void
Canvas::update()
{
    SDL_RenderPresent(m_renderer);
}

void
Canvas::draw(const Point& point) const
{
    Environment *env = Environment::get_instance();
    int x = point.x() - env->camera->x();
    int y = point.y() - env->camera->y();

    SDL_RenderDrawPoint(m_renderer, x, y);
}

void
Canvas::draw(const Point& point, const Color& color)
{
    if (color != m_color)
    {
        set_color(color);
    }

    draw(point);
}

void
Canvas::draw(const Line& line) const
{
    Environment *env = Environment::get_instance();
    int xa = line.a().x() - env->camera->x();
    int ya = line.a().y() - env->camera->y();
    int xb = line.b().x() - env->camera->x();
    int yb = line.b().y() - env->camera->y();

    SDL_RenderDrawLine(m_renderer, xa, ya, xb, yb);
}

void
Canvas::draw(const Line& line, const Color& color)
{
    if (color != m_color)
    {
        set_color(color);
    }

    draw(line);
}

void
Canvas::draw(const Rect& rect) const
{
    Environment *env = Environment::get_instance();
    int x = rect.x() - env->camera->x();
    int y = rect.y() - env->camera->y();

    SDL_Rect rectangle;
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = rect.w();
    rectangle.h = rect.h();

    SDL_RenderDrawRect(m_renderer, &rectangle);
}

void
Canvas::draw(const Rect& rect, const Color& color)
{
    if (color != m_color)
    {
        set_color(color);
    }

    draw(rect);
}

void
Canvas::fill(const Rect& rect) const
{
    Environment *env = Environment::get_instance();

    SDL_Rect rectangle;
    rectangle.x = rect.x() - env->camera->x();
    rectangle.y = rect.y() - env->camera->y();
    rectangle.w = rect.w();
    rectangle.h = rect.h();

    SDL_RenderFillRect(m_renderer, &rectangle);
}

void
Canvas::fill(const Rect& rect, const Color& color)
{
    if (color != m_color)
    {
        set_color(color);
    }

    fill(rect);
}

void
Canvas::draw(const Circle& circle) const
{
    Environment *env = Environment::get_instance();
    int cx = circle.center().x() - env->camera->x();
    int cy = circle.center().y() - env->camera->y();

    int radius = circle.radius();

    int error = 3 - (radius << 1);
    int i = 0, j = radius;

    do
    {
        draw_circle_points(cx, cy, i, j);

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

void
Canvas::fill(const Circle& circle) const
{
    Environment *env = Environment::get_instance();

    int cx = circle.center().x() - env->camera->x();
    int cy = circle.center().y() - env->camera->y();
    int radius = circle.radius();

    int error = 3 - (radius << 1);
    int i = 0, j = radius;

    do
    {
        fill_circle_points(cx, cy, i, j);

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

void
Canvas::fill(const Circle& circle, const Color& color)
{
    if (color != m_color)
    {
        set_color(color);
    }

    fill(circle);
}


void
Canvas::draw(const Circle& circle, const Color& color)
{
    if (color != m_color)
    {
        set_color(color);
    }

    draw(circle);
}


void
Canvas::draw_circle_points(int cx, int cy, int x, int y) const
{
    SDL_Point points[]
    {
        {cx + x, cy + y}, {cx + x, cy - y}, {cx + y, cy + x}, {cx + y, cy - x},
        {cx - x, cy + y}, {cx - x, cy - y}, {cx - y, cy + x}, {cx - y, cy - x}
    };

    SDL_RenderDrawPoints(m_renderer, points, 8);
}

void
Canvas::fill_circle_points(int cx, int cy, int x, int y) const
{
    draw(Line(Point(cx + x, cy + y), Point(cx + x, cy - y)));
    draw(Line(Point(cx - x, cy + y), Point(cx - x, cy - y)));
    draw(Line(Point(cx + y, cy + x), Point(cx + y, cy - x)));
    draw(Line(Point(cx - y, cy + x), Point(cx - y, cy - x)));
}

void
Canvas::draw(const Texture *texture, double x, double y) const
{
    if (not texture)
    {
        return;
    }

    Rect clip { 0, 0, (double) texture->size().first, (double) texture->size().second };

    draw(texture, clip, x, y);
}

void
Canvas::draw(const Texture *texture, Rect clip, double x, double y, double width, double height) const
{
    Environment *env = Environment::get_instance();

    int orig_x = (int) clip.x();
    int orig_y = (int) clip.y();
    int orig_width = (int) clip.w();
    int orig_height = (int) clip.h();

    int dest_x = (int) x - env->camera->x();
    int dest_y = (int) y - env->camera->y();

    int dest_width = ((int) width );
    if (width==0)
    {
        dest_width = ((int) texture->w());
    }else
    {
        // Do Nothing
    }

    int dest_height = ((int) height );
    if (height!=0)
    {
        dest_height = ((int) texture->h());
    }else
    {
        // Do Nothing
    }

    SDL_Rect orig { orig_x, orig_y, orig_width, orig_height };
    SDL_Rect dest { dest_x, dest_y, dest_width, dest_height };

    SDL_Texture *image = static_cast<SDL_Texture *>(texture->data());

    SDL_RenderCopy(m_renderer, image, &orig, &dest);
}

SDL_Renderer *
Canvas::renderer() const
{
    return m_renderer;
}

void
Canvas::draw(const string& text, double x, double y, const Color& color) const
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
    SDL_FreeSurface(surface);

    if (not texture)
    {
        return;
    }

    Environment *env = Environment::get_instance();

    int dest_x = (int) x - env->camera->x();
    int dest_y = (int) y - env->camera->y();

    SDL_Rect dest { dest_x, dest_y, width, height };

    SDL_RenderCopy(m_renderer, texture, NULL, &dest);

    SDL_DestroyTexture(texture);
}

Texture *
Canvas::render_text(const string& text, const Color& color)
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

SDL_Surface *
Canvas::bitmap() const
{
    return m_bitmap;
}

void
Canvas::draw(const Bitmap *bitmap, double, double) const
{
    SDL_UpdateTexture(m_texture, NULL, bitmap->pixels(), m_width * sizeof(Uint32));
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
}
