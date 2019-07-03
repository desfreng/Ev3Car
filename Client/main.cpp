#include "mywindow.h"

#ifdef __linux__
#include <X11/Xlib.h>
#endif

int main()
{
#ifdef __linux__
        XInitThreads();
#endif

        MyWindow window;
        return window.exec() ;
}
