#```Class Animation```
---comment---
--
##Public:
###```Animation(const string& image, double x, double y, double w, double h, int frames, unsigned long speed_in_ms, bool loop)```
---comment---
####Parameters
#####```const string& image```
---comment---
#####```double x```
---comment---
#####```double y```
---comment---
#####```double w```
---comment---
#####```double h```
---comment---
#####```int frames```
---comment---
#####```unsigned long speed_in_ms```
---comment---
#####```bool loop```
---comment---
--
###```~Animation()```
---comment---
--
###```bool is_done() const```
---comment---
--
###```void update(unsigned long elapsed)```
---comment---
####Parameters
#####```unsigned long elapsed```
---comment---
--
###```void draw(double x, double y)```
---comment---
####Parameters
#####```double x```
---comment---
#####```double y```
---comment---
####Variables
#####```Rect clip```
---comment---
#####```Environment *env```
---comment---
--
###```double w() const```
---comment---
--
###```double h() const```
---comment---
--
###```void set_row(int row)```
---comment---
####Parameters
#####```int row```
---comment---
####Variables
#####```int y```

--
##Private:
--
--
###```class Impl```
---comment---
####```Impl(const string& id, double x_, double y_, double w_, double h_, int f, unsigned long s, bool l_)```
---comment---
#####Parameters
######```const string& id```
---comment---
######```double x_```
---comment---
######```double y_```
---comment---
######```double w_```
---comment---
######```double h_```
---comment---
######```int f```
---comment---
######```unsigned long s```
---comment---
######```bool l_```
---comment---
#####Variables
######```Environment *env```
---comment---
#####```void reset()```
---comment---
###```double x```
---comment---
###```double y```
---comment---
###```double w```
---comment---
###```double h```
---comment---
###```int frames```
---comment---
###```unsigned long speed```
---comment---
###```bool loop```
---comment---
###```bool done```
---comment---
###```unsigned long last```
---comment---
###```int frame```
---comment---
###```shared_ptr<Texture> texture```
---comment---
--
--
###```unique_ptr<Impl> m_impl```
---comment---
--
