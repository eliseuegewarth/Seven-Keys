/*
 * Class which represents a text.
 *
 * Licença: LGPL. Sem copyright.
 */

#ifndef TEXT_H
#define TEXT_H

#include "core/object.hpp"
#include "core/color.hpp"

#include <memory>

using std::unique_ptr;

class Text : public Object
{
	public:
    	Text(Object *parent, const string& text, const Color& color = Color::BLACK);
    	~Text();

	private:
    	class Impl;
    	unique_ptr<Impl> m_impl;

    	void draw_self();
};

#endif
