#bitmap.cpp

##class Bitmap::Impl

####public:    
    m_bitmap = static_cast<SDL_Surface *>(data)
    int w() const { return m_w; }
    int h() const { return m_h; }
    SDL_Surface * data() const { return m_bitmap; }
    void * pixels() const { return m_bitmap->pixels; }
    void clear() { SDL_FillRect(m_bitmap, nullptr, 0); }

    void fill(const Rect& r, Uint32 color)
    {
        SDL_Rect rect { (int) r.x(), (int) r.y(), (int) r.w(), (int) r.h() };

        SDL_FillRect(m_bitmap, &rect, color);
    }

####private:
    int m_w, m_h;
    SDL_Surface *m_bitmap;


###Bitmap::Bitmap()
    void *data
    int w
    int h

###Bitmap::Bitmap()
    Canvas *canvas

###Bitmap::~Bitmap()

###void * Bitmap::data()

###int Bitmap::w() const

###int Bitmap::h() const

###Bitmap * Bitmap::from_file()
    SDL_Surface *bitmap = IMG_Load(path.c_str());


###void * Bitmap::pixels() const

###void Bitmap::clear()

###Uint32 Bitmap::getpixel(SDL_Surface *surface, int x, int y)

    int bpp = surface->format->BytesPerPixel;
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

void
Bitmap::putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
    int bpp = surface->format->BytesPerPixel;
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

###void Bitmap::fill(const Rect& r, Uint32 color)
