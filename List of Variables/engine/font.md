#Class Font
---Comment---
##Public:
###```typedef enum { NORMAL, BOLD, ITALIC } Style```
---Comment---
--
###```~Font()```
---Comment---
--
###```static Font * from_file(const string& path) throw (Exception)```
---Comment---
####Parameters
#####```const string& path```
---Comment---
####Variables
#####```TTF_Font *font```
---Comment---
--
###```TTF_Font * font() const```
---Comment---
--
###```int size() const```
---Comment---
--
###```Style style() const```
---Comment---
--
###```void set_size(int size)```
---Comment---
####Parameters
#####```int size```
---Comment---
--
###```void set_style(Style style)```
---Comment---
####Parameters
#####```Style style```
---Comment---
--
##Private:
###```unique_ptr<Impl> m_impl```
---Comment---
--
###```Font(TTF_Font *font, const string& path, int size)```
---Comment---
--
--
##class Font::Impl
---Comment---
###Public:
####```Impl(TTF_Font *font, const string& path, int size)```
---Comment---
--
####```~Impl()```
---Comment---
--
####```TTF_Font * font() const```
---Comment---
--
####```int size() const```
---Comment---
--
####```Style style() const```
---Comment---
--
####```void set_size(int size)```
---Comment---
#####Paramenters
######```int size```
---Comment---
#####Variables
######```Environment *env```
---Comment---
######```shared_ptr<Settings> settings```
---Comment---
######```double k```
---Comment---
--
####```void set_style(Style style)```
---Comment---
--
###Private:
####```TTF_Font *m_font```
---Comment---
--
####```string m_path```
---Comment---
--
####```int m_size```
---Comment---
--
####```Style m_style```
---Comment---
--
####```void change_size(int size)```
---Comment---
#####Parameters
######```int size```
---Comment---
#####Variables
######```TTF_Font *font```
---Comment---
--
--
