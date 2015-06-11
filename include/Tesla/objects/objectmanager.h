#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

/* Class to manage objects in scene 
  -- as of now, just keeps count of objects and helps in generating id
  */

template <class T>
class ObjectManager {
private:
	unsigned int count;

public:
	ObjectManager() {
		count = 0;
	}

	unsigned int getId() {
		return count++;
	}

	unsigned int getCount() {
		return count;
	}
};

#endif