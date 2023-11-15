#ifdef ATOMICSTRING_
#define ATOMICSTRING_

//To Initialize A AtomicString
void initAtomicString(AtomicString* str);

//To Allocate Memory For A AtomicString And Its Content
int allocAtomicString(AtomicString* str,const char* initialContent);

//To Free The Memory Of A AtomicString
void freeAtomicString(AtomicString* str);

//To Concantinate Two AtomicStrings
int concatAtomicString(AtomicString* result,const AtomicString* str1,const AtomicString* str2);

//To Extract A Substring From A AtomicString
void substringAtomicString(AtomicString* result,const AtomicString* str,size_t start,size_t end);

//To Get The Lenght Of A AtomicString
size_t lenAtomicString(const AtomicString* str);

//To Resize Memory For A AtomicString And Its Content
int resizeAtomicString(AtomicString* str,size_t size);

#endif /* ATOMICSTRING */
