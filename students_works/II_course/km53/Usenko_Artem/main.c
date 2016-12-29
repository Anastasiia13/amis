#include "struct.h"
#include "struct_function.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <malloc.h>
int main()
{
     Student user = create();
     print(&user);
     free(&user);
     return 0;
}
