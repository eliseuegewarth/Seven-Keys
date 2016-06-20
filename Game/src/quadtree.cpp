#include <cassert>
#include <iostream>

#include "quadtree.h"

/**
 * [Quadtree::Quadtree The constructor that initialize m_nodes array
 with its four pointers to null and assigns the
 value of pLevel to m_level and pBounds to m_bounds]
 * @method Quadtree::getIndex
 * @param  pLevel             [Number of stage that will be initialized]
 * @param  pBounds            [Environmental floor rectangle limit]
 */
Quadtree::Quadtree(int pLevel, Rect * pBounds)
{
	assert((pBounds != NULL) && "pBounds can't be NULL");
	m_level = pLevel;
	m_bounds = pBounds;

	for(size_t i = 0;  i < m_nodes.size(); i++)
	{
		m_nodes.at(i) = NULL;
	}
}

/**
 * [Quadtree::clear 				Method that assigning m_nodes array
 * 									with its four pointers to null
 * 									and free the memory.]
 * @method Quadtree::clear
 */
void Quadtree::clear()
{
	m_objects.clear();

	for(size_t i = 0;  i < m_nodes.size(); i++)
	{

		if(m_nodes.at(i) != NULL)
		{
			m_nodes.at(i)->clear();
			m_nodes.at(i) = NULL;
		}else{
			//do nothing
		}
	}
}

/**
 * [Quadtree::split 						Method to divide the room into
 * 											four with their respective limits]
 * @method Quadtree::split
 */
void Quadtree::split()
{
	//Limit of Width in map, it should be half the area of the rectangle
	int subWidth = (int)(m_bounds->height() / 2);
	//Limit of Height in map, it should be half the area of the rectangle
   	int subHeight = (int)(m_bounds->height() / 2);
   	int x = (int)m_bounds->x(); //Limit of Axis 'x' in map
   	int y = (int)m_bounds->y();  //Limit of Axis 'y' in map

   	m_nodes[0] = new Quadtree(m_level+1, new Rect(x + subWidth, y,
							  subWidth, subHeight));
   	m_nodes[1] = new Quadtree(m_level+1, new Rect(x, y,
							  subWidth, subHeight));
   	m_nodes[2] = new Quadtree(m_level+1, new Rect(x, y + subHeight,
							  subWidth, subHeight));
   	m_nodes[3] = new Quadtree(m_level+1, new Rect(x + subWidth, y + subHeight,
							  subWidth, subHeight));
}

/**
 * [Quadtree::getIndex Method to get the
 * player's position in the room]
 * @method Quadtree::getIndex
 * @param  pRect              [description]
 * @return                    [Position of player in map]
 */
int Quadtree::getIndex(Object * pRect)
{
	assert((pRect != NULL) && "pRect can't be NULL");
   	int index = -1; //Position of player in map
	//Definition of the middle of the quadrant in axis 'x'
   	double verticalMidpoint = m_bounds->x() + (m_bounds->width() / 2);
	//Definition of the middle of the quadrant in axis 'y'
   	double horizontalMidpoint = m_bounds->y() + (m_bounds->height() / 2);

   // Object can completely fit within the top quadrants
   //Define the upper quadrant
   	bool topQuadrant = (pRect->y() < horizontalMidpoint && pRect->y()
					 + pRect->height() < horizontalMidpoint);
	// Object can completely fit within the bottom quadrants
	//Define the lower quadrant
   	bool bottomQuadrant = (pRect->y() > horizontalMidpoint);

   	// Object can completely fit within the left quadrants
   	if (pRect->x() < verticalMidpoint && pRect->x()
		+ pRect->width() < verticalMidpoint)
	{
    	if (topQuadrant)
		{
        	index = 1;
      	}
      	else if (bottomQuadrant)
		{
	        index = 2;
	    }else{
			//do nothing
		}
	}
    // Object can completely fit within the right quadrants
    else if (pRect->x() > verticalMidpoint)
	{
	    if (topQuadrant)
		{
       		index = 0;
     	}
     	else if (bottomQuadrant)
		{
       		index = 3;
     	}else{
			//do nothing
		}
   	}else{
		//do nothing
	}
   	return index;
}

/**
 * [Quadtree::insert Inserts the stage object on the floor again]
 * @method Quadtree::insert
 * @param  pRect            []
 */
void Quadtree::insert(Object *pRect)
{
	assert((pRect != NULL) && "pRect can't be NULL");
	if (m_nodes[0] != NULL)
    {
    	int index = getIndex(pRect); //Position of player in map

    	if (index != -1)
    	{
    		m_nodes[index]->insert(pRect);
       		return;
     	}else{
			//do nothing
		}
   	}

   	m_objects.push_back(pRect);

   	if ((int)m_objects.size() > MAX_OBJECTS && m_level < MAX_LEVELS)
   	{
    	if (m_nodes[0] == NULL)
		{
         	split();
      	}else{
			//do nothing
		}

    	int i = 0; //Counter
     	while (i < (int)m_objects.size())
     	{
       		int index = getIndex(m_objects.at(i));
       		if (index != -1)
       		{
         		m_nodes[index]->insert(m_objects.at(i));
         		m_objects.erase(m_objects.begin() + i);
       		}else
       		{
         	i++;
       		}
     	}
   	}else{
		//do nothing
	}
}

 /**
  * [Quadtree::retrieve Insert objects of the previous phase
  * in a list to be loaded later]
  * @method Quadtree::retrieve
  * @param  pRect            [description]
  * @param  returnObjects    [Objects of the previous phase]
  */

list<Object*> Quadtree::retrieve(list<Object*> returnObjects, Object* pRect)
{
	assert((pRect != NULL) && "pRect can't be NULL");
	//assert((not returnObjects.empty()) && "list of objects can't be empty");
	int index = getIndex(pRect); //Position of Objects in previous phase
   	if (index != -1 && m_nodes.at(0) != NULL)
   	{
     	m_nodes.at(index)->retrieve(returnObjects, pRect);
   	}else{
		//do nothing
	}

 	for(size_t i = 0; i < m_objects.size(); i++)
 	{
 		returnObjects.push_back(m_objects.at(i));
 	}

   	return returnObjects;
 }
