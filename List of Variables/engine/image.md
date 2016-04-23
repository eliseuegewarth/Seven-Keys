#Class Image : public Object
---Comment---
##Public:
###```Image(Object *parent, const string& id, const string& image)```
--
###```~Image()```
--
##Private:
###```unique_ptr<Impl> m_impl```
--
###```void draw_self()```
--
--
##```class Image::Impl```
###public:
####```Impl(Image *parent, const string& texture)```
#####Parameters
######```Image *parent```
######```const string& texture```
#####Variables
######```Environment *env```
--
####```void draw_self()```
#####Variables
######```Environment *env```
###Private:
####```Image *m_parent```
--
####```shared_ptr<Texture> m_texture```
--
--
