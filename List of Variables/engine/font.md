#Class Font
##Public:
###```typedef enum { NORMAL, BOLD, ITALIC } Style```
--
###```~Font()```
--
###```static Font * from_file(const string& path) throw (Exception)```
####Variables
#####```TTF_Font *font```
--
###```TTF_Font * font() const```
--
###```int size() const```
--
###```Style style() const```
--
###```void set_size(int size)```
--
###```void set_style(Style style)```
--
##Private:
###```unique_ptr<Impl> m_impl```
--
###```Font(TTF_Font *font, const string& path, int size)```
--
--
##class Font::Impl
###Public:
####```Impl(TTF_Font *font, const string& path, int size)```
--
####```~Impl()```
--
####```TTF_Font * font() const```
--
####```int size() const```
--
####```Style style() const```
--
####```void set_size(int size)```
#####Paramenters
######```int size```
#####Variables
######```Environment *env```
######```shared_ptr<Settings> settings```
######```double k```
--
####```void set_style(Style style)```
--
###Private:
####```TTF_Font *m_font```
--
####```string m_path```
--
####```int m_size```
--
####```Style m_style```
--
####```void change_size(int size)```
#####Parameters
######```int size```
#####Variables
######```TTF_Font *font```
--
--
