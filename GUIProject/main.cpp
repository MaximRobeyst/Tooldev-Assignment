#include <qapplication.h>
#include "objForm.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	ObjForm objConverter;
	objConverter.show();
	return app.exec();

}
