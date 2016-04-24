#Class Listener
---Comment---

```c++
class SystemEvent;
class KeyboardEvent;
class JoyStickEvent;
class MouseButtonEvent;
class MouseMotionEvent;
```
---Comment---
--

##Public:
###```Listener()```
---Comment---
--
###```~Listener()```
---Comment---
--

###```virtual bool on_event(const SystemEvent& event)```
---Comment---
####Parameters
#####```const SystemEvent& event```
---Comment---
--
###```virtual bool on_event(const KeyboardEvent& event)```
---Comment---
####Parameters
#####```const KeyboardEvent& event```
---Comment---
--
###```virtual bool on_event(const JoyStickEvent& event)```
---Comment---
####Parameters
#####```const JoyStickEvent& event```
---Comment---
--
###```virtual bool on_event(const MouseButtonEvent& event)```
---Comment---
####Parameters
#####```const MouseButtonEvent& event```
---Comment---
--
###```virtual bool on_event(const MouseMotionEvent& event)```
---Comment---
####Parameters
#####```const MouseMotionEvent& event```
---Comment---
--

###```bool active() const```
---Comment---
--
###```void set_active(bool active)```
---Comment---
####Parameters
#####```bool active```
---Comment---
--
##Private:
###```unique_ptr<Impl> m_impl```
---Comment---
--
--
##```class Listener::Impl```
---Comment---
###Public:
####```Impl()```
---Comment---
--
####```~Impl()```
---Comment---
--
####```void set_active(bool active)```
---Comment---
####Parameters
#####```bool active```
---Comment---
--
####```bool active() const```
---Comment---
--
###Private:
####```bool m_active```
---Comment---
--
--
