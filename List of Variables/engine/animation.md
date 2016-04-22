#Class Animation
---comment---
--
##Public:
###Animation(const string& image, double x, double y, double w, double h, int frames, unsigned long speed_in_ms, bool loop = false);
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
--
##Private:
###```class Impl```
---comment---
--
###```unique_ptr<Impl> m_impl```
---comment---
--
