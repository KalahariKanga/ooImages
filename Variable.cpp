#include "Variable.h"
#include "Function.h"

Variable::Variable(Variable::Type t) : type(t)
{

}

Variable::Variable(const Variable& other)
{
	type = other.type;
	data = other.data;
}

Variable::~Variable()
{
}

Resource* Variable::getResource()
{
	if (type == Type::Real || type == Type::Void)
		return nullptr;
	else
		return (Resource*)data.get();
}

Variable Variable::duplicate()
{
	switch(type)
	{
	case Type::Void:
		return Variable(Type::Void);
	case Type::Real:
	{
		Variable v(Type::Real);
		v.set<float>(new float(*get<float>()));
		return v;
	}
	case Type::Colour:
	{
		Variable v(Type::Colour);
		v.set(static_pointer_cast<void>(make_shared<Colour>(*get<Colour>())));
		return v;
	}
	case Type::Selection:
	{
		Variable v(Type::Selection);
		v.set(static_pointer_cast<void>(make_shared<Selection>(*get<Selection>())));
		return v;
	}
	case Type::Mask:
	{
		Variable v(Type::Mask);
		Mask* thisMask = get<Mask>();
		Mask* s = new Mask(thisMask->width, thisMask->height);
		for (int cx = 0; cx < s->width; cx++)
			for (int cy = 0; cy < s->height; cy++)
				s->setValue(cx, cy, thisMask->getValue(cx, cy));
		v.set<Mask>(s);
		return v;
	}
	case Type::Kernel:
	{
		Variable v(Type::Kernel);
		v.set(static_pointer_cast<void>(make_shared<Kernel>(*get<Kernel>())));
		return v;	
	}
	case Type::Image:
	{
		Variable v(Type::Image);
		ImageObject* thisImage = get<ImageObject>();
		ImageObject* s = new ImageObject(thisImage->getWidth(),thisImage->getHeight());
		for (int cx = 0; cx < s->getWidth(); cx++)
			for (int cy = 0; cy < s->getHeight(); cy++)
				s->setPixel(cx, cy, thisImage->getPixel(cx, cy));
		v.set<ImageObject>(s);
		return v;
	}
	case Type::Function:
	{
		Variable v(Variable::Type::Function);
		v.set(get<Function>()->duplicate());
		return v;
	}
	default:
		std::cout << "Variable::duplicate() incomplete\n";
		return Variable(Variable::Type::Void);
	}
}
