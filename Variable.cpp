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
		v.set<Colour>(new Colour(*get<Colour>()));
		return v;
	}
	case Type::Selection:
	{
		Variable v(Type::Selection);
		Selection* thisSelection = get<Selection>();
		Selection* s = new Selection(thisSelection->width, thisSelection->height);
		for (int cx = 0; cx < s->width; cx++)
			for (int cy = 0; cy < s->height; cy++)
				s->setValue(cx, cy, thisSelection->getValue(cx, cy));
		v.set<Selection>(s);
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
		Kernel* thisKernel = get<Kernel>();
		Kernel* s = new Kernel(thisKernel->getSize());
		for (int cx = 0; cx < s->getSize(); cx++)
			for (int cy = 0; cy < s->getSize(); cy++)
				s->set(cx, cy, thisKernel->get(cx, cy));
		v.set<Kernel>(s);
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
		Variable v(Type::Function);
		Function* fn = new Function(get<Function>()->head, get<Function>()->argumentNames);
		v.set<Function>(fn);
		return v;
	}
	default:
		std::cout << "Variable::duplicate() incomplete\n";
		return Variable(Variable::Type::Void);
	}
}
