//
// https://www.jianshu.com/p/afbbdafabc8b
#include <jni.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <android/log.h>
#define LOG_TAG "System.out"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

#if defined(__ANDROID__)
typedef int64_t __int64;
#endif

/************************************byte_Begin*************************************/
// 静态方法和对象方法的不同就在于
// 实例对象方法JNI方法的第二个参数为 jobject(JNIEnv *env, jobject jobj)
// 静态方法 JNI方法 第二个参数为 jclass   (JNIEnv *env, jclass jcls);
JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_booleanNvMethod00
        (JNIEnv *env, jobject jobj) {

    jclass jcla = (*env)->GetObjectClass(env, jobj);

    jfieldID fid = (*env)->GetFieldID(env, jcla, "booleanValue", "Z");


    jboolean jbooleanValue = (*env)->GetBooleanField(env, jobj, fid);


    unsigned char i = (unsigned char) jbooleanValue;

    LOGI("@@JNI(unsigned char)NvMethod00 get jfieldID(unsigned char)Value is :   %p", i);

    unsigned char j = JNI_FALSE;
    (*env)->SetBooleanField(env, jobj, fid, (jboolean)j);  // 在JNI中设置 java 层booleanValue新的值
    //(*env)->SetBooleanField(env, jobj, fid, JNI_FALSE);
    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIboolean00", "()V");
    (*env)->CallVoidMethod(env, jobj, mid); // 调用 Java的Object 函数   void callbyJNIboolean00()

    return;
}


JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_booleanNvMethod01
        (JNIEnv *env, jobject jobj, jboolean booleanValue) {

    jclass jcla = (*env)->GetObjectClass(env, jobj);
    unsigned char cbooleanValue = (unsigned char)booleanValue;  // jboolean 强转为 C语言(unsigned char) 类型

    LOGI("@@JNI booleanNvMethod01 param jboolean is :   %p", cbooleanValue);

    cbooleanValue =  JNI_TRUE;

    jboolean new_booleanValue =(jboolean)cbooleanValue;
    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIboolean01", "(Z)V");
    (*env)->CallVoidMethod(env, jobj, mid,new_booleanValue); // 调用 Java的Object 函数   void callbyJNIboolean00()
    return;
}



JNIEXPORT jboolean JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_booleanNvMethod10
        (JNIEnv *env, jobject jobj) {
    jclass jcla = (*env)->GetObjectClass(env, jobj);

    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIboolean10", "()Z");
    jboolean jbooleanValue = (*env)->CallBooleanMethod(env, jobj, mid);
    unsigned char cbooleanvalue = (unsigned char)jbooleanValue;  // jboolean 转为 C语言 unsigned char 类型 【C语言没有boolean类型】

    LOGI("@@JNI  callbyJNIboolean10 return  jboolean is :   %p", cbooleanvalue);
    cbooleanvalue =JNI_FALSE;

    jboolean result_booleanValue = (jboolean)  cbooleanvalue;


    return result_booleanValue;
}


JNIEXPORT jboolean  JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_booleanNvMethod11
        (JNIEnv *env, jobject jobj, jboolean booleanValue) {


    jclass jcla = (*env)->GetObjectClass(env, jobj);
    unsigned char cbooleanValue = (unsigned char)booleanValue;  // jboolean 强转为 C语言(unsigned char) 类型

    LOGI("@@JNI  callbyJNIboolean11 params  jboolean is :   %p", cbooleanValue);

    cbooleanValue =JNI_TRUE;

    jboolean  jboolean_result = (jboolean)cbooleanValue;
    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIboolean11", "(Z)Z");

    jboolean return_booleanValue = (*env)->CallBooleanMethod(env, jobj, mid,jboolean_result);

    unsigned char cbooleanValue_return = (unsigned char)return_booleanValue;
    LOGI("@@JNI  callbyJNIboolean11  return jboolean : %p", cbooleanValue_return);

    return return_booleanValue;

}



JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_booleanStaticNvMethod00
        (JNIEnv *env, jclass jcla) {

    jfieldID fid = (*env)->GetStaticFieldID(env, jcla, "booleanStaticValue", "Z");
    jboolean jbooleanValue = (*env)->GetStaticBooleanField(env, jcla, fid);  // 获得 静态boolean属性

    unsigned char c_booleanValue = (unsigned char) jbooleanValue;
    LOGI("Jni.c@@(unsigned char)StaticNvMethod00  called (unsigned char)StaticValue is: %p",c_booleanValue);
    unsigned char  j = JNI_TRUE;
    (*env)->SetStaticBooleanField(env, jcla, fid, (jboolean)j);    // 设置 静态属性

    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticboolean00", "()V"); // 指定静态方法
    (*env)->CallStaticVoidMethod(env, jcla, mid);  // 调用返回值为空的静态方法

    return;
}

JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_booleanStaticNvMethod01
        (JNIEnv *env,jclass jcla, jboolean booleanValue) {


    unsigned char cbooleanValue_value = (unsigned char ) booleanValue;

    LOGI("Jni.c@@(unsigned char)StaticNvMethod01  called  param(unsigned char) is: %p",cbooleanValue_value);

    cbooleanValue_value = JNI_TRUE;
    jboolean  jbooleanValue = (jboolean)cbooleanValue_value;

    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticboolean01", "(Z)V");
    (*env)->CallStaticVoidMethod(env, jcla, mid, jbooleanValue);  // 调用返回值为空的静态方法

    return;
}


JNIEXPORT jboolean JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_booleanStaticNvMethod10
        (JNIEnv *env, jclass jcla) {


    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticboolean10", "()Z");
    jboolean mReturnbooleanValue =  (*env)->CallStaticBooleanMethod(env, jcla, mid);  // 调用返回值为空的静态方法

    unsigned char cbooleanValue_value = (unsigned char) mReturnbooleanValue;
    LOGI("@@JNI  callbyJNIStaticboolean10 return  jboolean is :   %p", cbooleanValue_value);

    cbooleanValue_value =JNI_FALSE;


    jboolean  jbooleanValue = (jboolean) cbooleanValue_value;


    return jbooleanValue;
}

JNIEXPORT jboolean JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_booleanStaticNvMethod11
        (JNIEnv *env, jclass jcla, jboolean booleanValue) {


    unsigned char cbooleanValue = (unsigned char)booleanValue;  // jboolean 转为 C语言(unsigned char) 类型
    LOGI("@@JNI  callbyJNIStaticboolean11 param  jboolean is :   %p", cbooleanValue);

    cbooleanValue = JNI_TRUE;


    jboolean jValue = (jboolean) cbooleanValue;

    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticboolean11", "(Z)Z");
    jboolean mReturnbooleanValue =  (*env)->CallStaticBooleanMethod(env, jcla , mid ,jValue);  //  调用 java的静态方法
    cbooleanValue = (unsigned char)mReturnbooleanValue;
    LOGI("@@JNI  callbyJNIStaticboolean11 return result  jboolean is :   %p", cbooleanValue);

    return mReturnbooleanValue;
}
/************************************Boolean-End*************************************/



/************************************byte_Begin*************************************/
// 静态方法和对象方法的不同就在于
// 实例对象方法JNI方法的第二个参数为 jobject(JNIEnv *env, jobject jobj)
// 静态方法 JNI方法 第二个参数为 jclass   (JNIEnv *env, jclass jcls);
JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_byteNvMethod00
        (JNIEnv *env, jobject jobj) {

    jclass jcla = (*env)->GetObjectClass(env, jobj);

    jfieldID fid = (*env)->GetFieldID(env, jcla, "byteValue", "B");


    jbyte jbyteValue = (*env)->GetByteField(env, jobj, fid);


    signed char i = (signed char) jbyteValue;

    LOGI("@@JNI(signed char)NvMethod00 get jfieldID(signed char)Value is :   %p", i);

    signed char j = (signed char )0xfa;
    (*env)->SetByteField(env, jobj, fid, (jbyte)j);  // 在JNI中设置 java 层byteValue新的值

    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIbyte00", "()V");
    (*env)->CallVoidMethod(env, jobj, mid); // 调用 Java的Object 函数   void callbyJNIbyte00()

    return;
}


JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_byteNvMethod01
        (JNIEnv *env, jobject jobj, jbyte byteValue) {

    jclass jcla = (*env)->GetObjectClass(env, jobj);
    signed char cbyteValue = (signed char)0x00;
    cbyteValue = (signed char) byteValue;  // jbyte 强转为 C语言(signed char) 类型

    LOGI("@@JNI byteNvMethod01 param jbyte is :   %p", cbyteValue);

    cbyteValue =  (signed char )0x1a;

    jbyte new_byteValue =(jbyte)cbyteValue;
    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIbyte01", "(B)V");
    (*env)->CallVoidMethod(env, jobj, mid,new_byteValue); // 调用 Java的Object 函数   void callbyJNIbyte00()
    return;
}



JNIEXPORT jbyte JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_byteNvMethod10
        (JNIEnv *env, jobject jobj) {
    jclass jcla = (*env)->GetObjectClass(env, jobj);

    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIbyte10", "()B");
    jbyte jbyteValue = (*env)->CallByteMethod(env, jobj, mid);

    signed char cbyteValue = (signed char)0x00;
    cbyteValue = (signed char) jbyteValue;  // jbyte 强转为 C语言(signed char) 类型

    LOGI("@@JNI  callbyJNIbyte10 return  jbyte is :   %p", cbyteValue);
    signed char   cbyteValue_1 =(signed char )0x0e;

    jbyte result_byteValue = (jbyte)  cbyteValue_1;


    return result_byteValue;
}


JNIEXPORT jbyte  JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_byteNvMethod11
        (JNIEnv *env, jobject jobj, jbyte byteValue) {


    jclass jcla = (*env)->GetObjectClass(env, jobj);
    signed char cbyteValue = (signed char)0x00;
    cbyteValue = (signed char) byteValue;  // jbyte 强转为 C语言(signed char) 类型

    LOGI("@@JNI  callbyJNIbyte11 params  jbyte is :   %p", cbyteValue);

    cbyteValue = (signed char )0xc2;

    jbyte  jbyte_result = (jbyte)cbyteValue;
    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIbyte11", "(B)B");

    jbyte return_byteValue = (*env)->CallByteMethod(env, jobj, mid,jbyte_result);

    signed char cbyteValue_return = (signed char)return_byteValue;
    LOGI("@@JNI  callbyJNIbyte11  return jbyte : %p", cbyteValue_return);

    return return_byteValue;

}



JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_byteStaticNvMethod00
        (JNIEnv *env, jclass jcla) {

    jfieldID fid = (*env)->GetStaticFieldID(env, jcla, "byteStaticValue", "B");
    jbyte jbyteValue = (*env)->GetStaticByteField(env, jcla, fid);  // 获得 静态byte属性

    signed char cbyteValue = (signed char)0x00;
    cbyteValue = (signed char) jbyteValue;  // jbyte 强转为 C语言(signed char) 类型
    LOGI("Jni.c@@(signed char)StaticNvMethod00  called (signed char)StaticValue is: %p",cbyteValue);
    signed char  j = (signed char )0x08;
    (*env)->SetStaticByteField(env, jcla, fid, (jbyte)j);    // 设置 静态属性

    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticbyte00", "()V"); // 指定静态方法
    (*env)->CallStaticVoidMethod(env, jcla, mid);  // 调用返回值为空的静态方法

    return;
}

JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_byteStaticNvMethod01
        (JNIEnv *env,jclass jcla, jbyte byteValue) {


    signed char cbyteValue = (signed char)0x00;
    cbyteValue = (signed char) byteValue;  // jbyte 强转为 C语言(signed char) 类型

    LOGI("Jni.c@@(signed char)StaticNvMethod01  called  param(signed char) is: %p",cbyteValue);

    signed char cbyteValue_new = (signed char )0x78;
    jbyte  jbyteValue = (jbyte)cbyteValue_new;

    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticbyte01", "(B)V");
    (*env)->CallStaticVoidMethod(env, jcla, mid, jbyteValue);  // 调用返回值为空的静态方法

    return;
}


JNIEXPORT jbyte JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_byteStaticNvMethod10
        (JNIEnv *env, jclass jcla) {


    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticbyte10", "()B");
    jbyte mReturnbyteValue =  (*env)->CallStaticByteMethod(env, jcla, mid);  // 调用返回值为空的静态方法

    signed char cbyteValue_value = (signed char)0x00;
    cbyteValue_value = (signed char) mReturnbyteValue;  // jbyte 强转为 C语言(signed char) 类型

    LOGI("@@JNI  callbyJNIStaticbyte10 return  jbyte is :   %p", cbyteValue_value);

    cbyteValue_value =(signed char )0x38;


    jbyte  jbyteValue = (jbyte) cbyteValue_value;


    return jbyteValue;
}

JNIEXPORT jbyte JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_byteStaticNvMethod11
        (JNIEnv *env, jclass jcla, jbyte byteValue) {

    signed char cbyteValue = (signed char)0x00;
    cbyteValue = (signed char) byteValue;  // jbyte 强转为 C语言(signed char) 类型
    LOGI("@@JNI  callbyJNIStaticbyte11 param  jbyte is :   %p", cbyteValue);

    cbyteValue = (signed char )0x21;


    jbyte jValue = (jbyte) cbyteValue;

    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticbyte11", "(B)B");
    jbyte mReturnbyteValue =  (*env)->CallStaticByteMethod(env, jcla , mid ,jValue);  //  调用 java的静态方法
    cbyteValue = (signed char)mReturnbyteValue;
    LOGI("@@JNI  callbyJNIStaticbyte11 return result  jbyte is :   %p", cbyteValue);

    return mReturnbyteValue;
}
/************************************Byte-End*************************************/

/************************************char_Begin*************************************/
// 静态方法和对象方法的不同就在于
// 实例对象方法JNI方法的第二个参数为 jobject(JNIEnv *env, jobject jobj)
// 静态方法 JNI方法 第二个参数为 jclass   (JNIEnv *env, jclass jcls);
JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_charNvMethod00
        (JNIEnv *env, jobject jobj) {

    jclass jcla = (*env)->GetObjectClass(env, jobj);

    jfieldID fid = (*env)->GetFieldID(env, jcla, "charValue", "C");


    jchar jcharValue = (*env)->GetCharField(env, jobj, fid);


    unsigned short i = (unsigned short) jcharValue;

    LOGI("@@JNI charNvMethod00 get jfieldID charValue is :   %c", i);


    (*env)->SetCharField(env, jobj, fid, 'Q');  // 在JNI中设置 java 层charValue新的值

    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIchar00", "()V");
    (*env)->CallVoidMethod(env, jobj, mid); // 调用 Java的Object 函数   void callbyJNIchar00()

    return;
}


JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_charNvMethod01
        (JNIEnv *env, jobject jobj, jchar charValue) {

    jclass jcla = (*env)->GetObjectClass(env, jobj);
    unsigned short ccharValue = (unsigned short)charValue;  // jchar 强转为 C语言 unsigned short 类型

    LOGI("@@JNI  charNvMethod01 param jchar is :   %c", ccharValue);

    ccharValue =  'W';

    jchar new_charValue =(jchar)ccharValue;
    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIchar01", "(C)V");
    (*env)->CallVoidMethod(env, jobj, mid,new_charValue); // 调用 Java的Object 函数   void callbyJNIchar00()
    return;
}



JNIEXPORT jchar JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_charNvMethod10
        (JNIEnv *env, jobject jobj) {
    jclass jcla = (*env)->GetObjectClass(env, jobj);

    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIchar10", "()C");
    jchar jcharValue = (*env)->CallCharMethod(env, jobj, mid);
    unsigned short ccharvalue = (unsigned short)jcharValue;  // jchar 转为 C语言 char 类型

    LOGI("@@JNI  callbyJNIchar10 return  jchar is :   %c", ccharvalue);
    ccharvalue = 'E';

    jchar result_charValue = (jchar)  ccharvalue;


    return result_charValue;
}


JNIEXPORT jchar  JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_charNvMethod11
        (JNIEnv *env, jobject jobj, jchar charValue) {


    jclass jcla = (*env)->GetObjectClass(env, jobj);
    unsigned short ccharValue = (unsigned short)charValue;  // jchar 强转为 C语言 char 类型

    LOGI("@@JNI  callbyJNIchar11 params  jchar is :   %c", ccharValue);

    ccharValue = 'T';

    jchar  jchar_result = (jchar)ccharValue;
    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIchar11", "(C)C");

    jchar return_charValue = (*env)->CallCharMethod(env, jobj, mid,jchar_result);

    unsigned short ccharValue_return = (unsigned short)return_charValue;
    LOGI("@@JNI  callbyJNIchar11  return jchar : %c", ccharValue_return);

    return return_charValue;

}



JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_charStaticNvMethod00
        (JNIEnv *env, jclass jcla) {

    jfieldID fid = (*env)->GetStaticFieldID(env, jcla, "charStaticValue", "C");
    jchar jcharValue = (*env)->GetStaticCharField(env, jcla, fid);  // 获得 静态char属性

    unsigned short c_charValue = (unsigned short) jcharValue;
    LOGI("Jni.c@@ charStaticNvMethod00  called  charStaticValue is: %c",c_charValue);
    (*env)->SetStaticCharField(env, jcla, fid, (jchar)'O');    // 设置 静态属性

    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticchar00", "()V"); // 指定静态方法
    (*env)->CallStaticVoidMethod(env, jcla, mid);  // 调用返回值为空的静态方法

    return;
}

JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_charStaticNvMethod01
        (JNIEnv *env,jclass jcla, jchar charValue) {


    unsigned short ccharValue_value = ( unsigned short ) charValue;

    LOGI("Jni.c@@ charStaticNvMethod01  called  param char is: %c",ccharValue_value);

    ccharValue_value = 'P';
    jchar  jcharValue = (jchar)ccharValue_value;

    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticchar01", "(C)V");
    (*env)->CallStaticVoidMethod(env, jcla, mid, jcharValue);  // 调用返回值为空的静态方法

    return;
}


JNIEXPORT jchar JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_charStaticNvMethod10
        (JNIEnv *env, jclass jcla) {


    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticchar10", "()C");
    jchar mReturncharValue =  (*env)->CallStaticCharMethod(env, jcla, mid);  // 调用返回值为空的静态方法

    unsigned short ccharValue_value = (unsigned short) mReturncharValue;
    LOGI("@@JNI  callbyJNIStaticchar10 return  jchar is :   %c", ccharValue_value);

    ccharValue_value = 'K';


    jchar  jcharValue = (jchar) ccharValue_value;


    return jcharValue;
}

JNIEXPORT jchar JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_charStaticNvMethod11
        (JNIEnv *env, jclass jcla, jchar charValue) {


    unsigned short ccharValue = (unsigned short) charValue;  // jchar 转为 C语言 char 类型
    LOGI("@@JNI  callbyJNIStaticchar11 param  jchar is :   %c", ccharValue);

    ccharValue = 'V';


    jchar char_jValue = (jchar) ccharValue;

    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticchar11", "(C)C");
    jchar mReturncharValue =  (*env)->CallStaticCharMethod(env, jcla , mid , char_jValue);  //  调用 java的静态方法
    ccharValue = (unsigned short)mReturncharValue;
    LOGI("@@JNI  callbyJNIStaticchar11 return result  jchar is :   %c", ccharValue);

    return mReturncharValue;
}
/************************************Char-End*************************************/


/************************************short_Begin*************************************/
// 静态方法和对象方法的不同就在于
// 实例对象方法JNI方法的第二个参数为 jobject(JNIEnv *env, jobject jobj)
// 静态方法 JNI方法 第二个参数为 jclass   (JNIEnv *env, jclass jcls);
JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_shortNvMethod00
        (JNIEnv *env, jobject jobj) {

    jclass jcla = (*env)->GetObjectClass(env, jobj);

    jfieldID fid = (*env)->GetFieldID(env, jcla, "shortValue", "S");


    jshort jshortValue = (*env)->GetShortField(env, jobj, fid);


    short i = (short) jshortValue;

    LOGI("@@JNI shortNvMethod00 get jfieldID shortValue is :   %d", i);


    (*env)->SetShortField(env, jobj, fid, 1000);  // 在JNI中设置 java 层shortValue新的值

    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIshort00", "()V");
    (*env)->CallVoidMethod(env, jobj, mid); // 调用 Java的Object 函数   void callbyJNIshort00()

    return;
}


JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_shortNvMethod01
        (JNIEnv *env, jobject jobj, jshort shortValue) {

    jclass jcla = (*env)->GetObjectClass(env, jobj);
    short cshortValue = (short)shortValue;  // jshort 强转为 C语言 short 类型

    LOGI("@@JNI  shortNvMethod01 param jshort is :   %d", cshortValue);

    cshortValue =  cshortValue + 95;

    jshort new_shortValue =(jshort)cshortValue;
    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIshort01", "(S)V");
    (*env)->CallVoidMethod(env, jobj, mid,new_shortValue); // 调用 Java的Object 函数   void callbyJNIshort00()
    return;
}



JNIEXPORT jshort JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_shortNvMethod10
        (JNIEnv *env, jobject jobj) {
    jclass jcla = (*env)->GetObjectClass(env, jobj);

    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIshort10", "()S");
    jshort jshortValue = (*env)->CallShortMethod(env, jobj, mid);
    short cshortvalue = (short)jshortValue;  // jshort 转为 C语言 short 类型

    LOGI("@@JNI  callbyJNIshort10 return  jshort is :   %d", cshortvalue);
    cshortvalue = cshortvalue + 12;

    jshort result_shortValue = (jshort)  cshortvalue;


    return result_shortValue;
}


JNIEXPORT jshort  JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_shortNvMethod11
        (JNIEnv *env, jobject jobj, jshort shortValue) {


    jclass jcla = (*env)->GetObjectClass(env, jobj);
    short cshortValue = (short)shortValue;  // jshort 强转为 C语言 short 类型

    LOGI("@@JNI  callbyJNIshort11 params  jshort is :   %d", cshortValue);

    cshortValue = cshortValue + 54;

    jshort  jshort_result = (jshort)cshortValue;
    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIshort11", "(S)S");

    jshort return_shortValue = (*env)->CallShortMethod(env, jobj, mid,jshort_result);

    short cshortValue_return = (short)return_shortValue;
    LOGI("@@JNI  callbyJNIshort11  return jshort : %d", cshortValue_return);

    return return_shortValue;

}



JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_shortStaticNvMethod00
        (JNIEnv *env, jclass jcla) {

    jfieldID fid = (*env)->GetStaticFieldID(env, jcla, "shortStaticValue", "S");
    jshort jshortValue = (*env)->GetStaticShortField(env, jcla, fid);  // 获得 静态short属性

    short c_shortValue = (short) jshortValue;
    LOGI("Jni.c@@ shortStaticNvMethod00  called  shortStaticValue is: %d",c_shortValue);
    (*env)->SetStaticShortField(env, jcla, fid, 500);    // 设置 静态属性

    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticshort00", "()V"); // 指定静态方法
    (*env)->CallStaticVoidMethod(env, jcla, mid);  // 调用返回值为空的静态方法

    return;
}

JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_shortStaticNvMethod01
        (JNIEnv *env,jclass jcla, jshort shortValue) {


    short cshortValue_value = ( short ) shortValue;

    LOGI("Jni.c@@ shortStaticNvMethod01  called  param short is: %d",cshortValue_value);

    cshortValue_value = cshortValue_value + 876;
    jshort  jshortValue = (jshort)cshortValue_value;

    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticshort01", "(S)V");
    (*env)->CallStaticVoidMethod(env, jcla, mid, jshortValue);  // 调用返回值为空的静态方法

    return;
}


JNIEXPORT jshort JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_shortStaticNvMethod10
        (JNIEnv *env, jclass jcla) {


    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticshort10", "()S");
    jshort mReturnshortValue =  (*env)->CallStaticShortMethod(env, jcla, mid);  // 调用返回值为空的静态方法

    short cshortValue_value = (short) mReturnshortValue;
    LOGI("@@JNI  callbyJNIStaticshort10 return  jshort is :   %d", cshortValue_value);

    cshortValue_value = cshortValue_value + 21;


    jshort  jshortValue = (jshort) cshortValue_value;


    return jshortValue;
}

JNIEXPORT jshort JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_shortStaticNvMethod11
        (JNIEnv *env, jclass jcla, jshort shortValue) {


    short cshortValue = (short) shortValue;  // jshort 转为 C语言 short 类型
    LOGI("@@JNI  callbyJNIStaticshort11 param  jshort is :   %d", cshortValue);

    cshortValue = cshortValue + 23;


    jshort short_jValue = (jshort) cshortValue;

    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticshort11", "(S)S");
    jshort mReturnshortValue =  (*env)->CallStaticShortMethod(env, jcla , mid , short_jValue);  //  调用 java的静态方法
    cshortValue = (short)mReturnshortValue;
    LOGI("@@JNI  callbyJNIStaticshort11 return result  jshort is :   %d", cshortValue);

    return mReturnshortValue;
}
/************************************Short-End*************************************/


/************************************int_Begin*************************************/
// 静态方法和对象方法的不同就在于
// 实例对象方法JNI方法的第二个参数为 jobject(JNIEnv *env, jobject jobj)
// 静态方法 JNI方法 第二个参数为 jclass   (JNIEnv *env, jclass jcls);
JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_intNvMethod00
        (JNIEnv *env, jobject jobj) {

    jclass jcla = (*env)->GetObjectClass(env, jobj);

    jfieldID fid = (*env)->GetFieldID(env, jcla, "intValue", "I");


    jint jintValue = (*env)->GetIntField(env, jobj, fid);


    long i = (long) jintValue;

    LOGI("@@JNI intNvMethod00 get jfieldID intValue is :   %d", i);


    (*env)->SetIntField(env, jobj, fid, 1234);  // 在JNI中设置 java 层intValue新的值

    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIint00", "()V");
    (*env)->CallVoidMethod(env, jobj, mid); // 调用 Java的Object 函数   void callbyJNIint00()

    return;
}


JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_intNvMethod01
        (JNIEnv *env, jobject jobj, jint intValue) {

    jclass jcla = (*env)->GetObjectClass(env, jobj);
    long cintValue = (long)intValue;  // jint 强转为 C语言 int 类型

    LOGI("@@JNI  intNvMethod01 param jint is :   %d", cintValue);

    cintValue =  cintValue + 100;

    jint new_intValue =(jint)cintValue;
    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIint01", "(I)V");
    (*env)->CallVoidMethod(env, jobj, mid,new_intValue); // 调用 Java的Object 函数   void callbyJNIint00()
    return;
}



JNIEXPORT jint JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_intNvMethod10
        (JNIEnv *env, jobject jobj) {
    jclass jcla = (*env)->GetObjectClass(env, jobj);

    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIint10", "()I");
    jint jintValue = (*env)->CallIntMethod(env, jobj, mid);
    long cintvalue = (long)jintValue;  // jint 转为 C语言 int 类型

    LOGI("@@JNI  callbyJNIint10 return  jint is :   %d", cintvalue);
    cintvalue = cintvalue + 200;

    jint result_intValue = (jint)  cintvalue;


    return result_intValue;
}


JNIEXPORT jint  JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_intNvMethod11
        (JNIEnv *env, jobject jobj, jint intValue) {


    jclass jcla = (*env)->GetObjectClass(env, jobj);
    long cintValue = (long)intValue;  // jint 强转为 C语言 int 类型

    LOGI("@@JNI  callbyJNIint11 params  jint is :   %d", cintValue);

    cintValue = cintValue + 300;

    jint  jint_result = (jint)cintValue;
    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIint11", "(I)I");

    jint return_intValue = (*env)->CallIntMethod(env, jobj, mid,jint_result);

    long cintValue_return = (long)return_intValue;
    LOGI("@@JNI  callbyJNIint11  return jint : %d", cintValue_return);

    return return_intValue;

}



JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_intStaticNvMethod00
        (JNIEnv *env, jclass jcla) {

    jfieldID fid = (*env)->GetStaticFieldID(env, jcla, "intStaticValue", "I");
    jint jintValue = (*env)->GetStaticIntField(env, jcla, fid);  // 获得 静态int属性

    long c_intValue = (long) jintValue;
    LOGI("Jni.c@@ intStaticNvMethod00  called  intStaticValue is: %d",c_intValue);
    (*env)->SetStaticIntField(env, jcla, fid, 500);    // 设置 静态属性

    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticint00", "()V"); // 指定静态方法
    (*env)->CallStaticVoidMethod(env, jcla, mid);  // 调用返回值为空的静态方法

    return;
}

JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_intStaticNvMethod01
        (JNIEnv *env,jclass jcla, jint intValue) {


    long cintValue_value = ( long ) intValue;

    LOGI("Jni.c@@ intStaticNvMethod01  called  param int is: %d",cintValue_value);

    cintValue_value = cintValue_value + 1;
    jint  jintValue = (jint)cintValue_value;

    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticint01", "(I)V");
    (*env)->CallStaticVoidMethod(env, jcla, mid, jintValue);  // 调用返回值为空的静态方法

    return;
}


JNIEXPORT jint JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_intStaticNvMethod10
        (JNIEnv *env, jclass jcla) {


    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticint10", "()I");
    jint mReturnintValue =  (*env)->CallStaticIntMethod(env, jcla, mid);  // 调用返回值为空的静态方法

    long cintValue_value = (long) mReturnintValue;
    LOGI("@@JNI  callbyJNIStaticint10 return  jint is :   %d", cintValue_value);

    cintValue_value = cintValue_value + 11;


    jint  jintValue = (jint) cintValue_value;


    return jintValue;
}

JNIEXPORT jint JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_intStaticNvMethod11
        (JNIEnv *env, jclass jcla, jint intValue) {


    long cintValue = (long) intValue;  // jint 转为 C语言 char* 类型
    LOGI("@@JNI  callbyJNIStaticint11 param  jint is :   %d", cintValue);

    cintValue = cintValue + 11;


    jint int_jValue = (jint) cintValue;

    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticint11", "(I)I");
    jint mReturnintValue =  (*env)->CallStaticIntMethod(env, jcla , mid , int_jValue);  //  调用 java的静态方法 来完成字符串的 拼接
    cintValue = (long)mReturnintValue;
    LOGI("@@JNI  callbyJNIStaticint11 return result  jint is :   %d", cintValue);

    return mReturnintValue;
}
/************************************Int-End*************************************/



/************************************long_Begin*************************************/
// 静态方法和对象方法的不同就在于
// 实例对象方法JNI方法的第二个参数为 jobject(JNIEnv *env, jobject jobj)
// 静态方法 JNI方法 第二个参数为 jclass   (JNIEnv *env, jclass jcls);
JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_longNvMethod00
        (JNIEnv *env, jobject jobj) {

    jclass jcla = (*env)->GetObjectClass(env, jobj);

    jfieldID fid = (*env)->GetFieldID(env, jcla, "longValue", "J");


    jlong jlongValue = (*env)->GetLongField(env, jobj, fid);


    __int64 i = (__int64) jlongValue;

    LOGI("@@JNI longNvMethod00 get jfieldID longValue is :   %ld", i);


    (*env)->SetLongField(env, jobj, fid, 1234567891011);  // 在JNI中设置 java 层longValue新的值

    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIlong00", "()V");
    (*env)->CallVoidMethod(env, jobj, mid); // 调用 Java的Object 函数   void callbyJNIlong00()

    return;
}


JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_longNvMethod01
        (JNIEnv *env, jobject jobj, jlong longValue) {

    jclass jcla = (*env)->GetObjectClass(env, jobj);
    __int64 clongValue = (__int64)longValue;  // jlong 强转为 C语言 long 类型

    LOGI("@@JNI  longNvMethod01 param jlong is :   %ld", clongValue);

    clongValue =  clongValue + 24795;

    jlong new_longValue =(jlong)clongValue;
    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIlong01", "(J)V");
    (*env)->CallVoidMethod(env, jobj, mid,new_longValue); // 调用 Java的Object 函数   void callbyJNIlong00()
    return;
}



JNIEXPORT jlong JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_longNvMethod10
        (JNIEnv *env, jobject jobj) {
    jclass jcla = (*env)->GetObjectClass(env, jobj);

    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIlong10", "()J");
    jlong jlongValue = (*env)->CallLongMethod(env, jobj, mid);
    __int64 clongvalue = (__int64)jlongValue;  // jlong 转为 C语言 long 类型

    LOGI("@@JNI  callbyJNIlong10 return  jlong is :   %ld", clongvalue);
    clongvalue = clongvalue + 123678;

    jlong result_longValue = (jlong)  clongvalue;


    return result_longValue;
}


JNIEXPORT jlong  JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_longNvMethod11
        (JNIEnv *env, jobject jobj, jlong longValue) {


    jclass jcla = (*env)->GetObjectClass(env, jobj);
    __int64 clongValue = (__int64)longValue;  // jlong 强转为 C语言 long 类型

    LOGI("@@JNI  callbyJNIlong11 params  jlong is :   %ld", clongValue);

    clongValue = clongValue + 567432;

    jlong  jlong_result = (jlong)clongValue;
    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIlong11", "(J)J");

    jlong return_longValue = (*env)->CallLongMethod(env, jobj, mid,jlong_result);

    __int64 clongValue_return = (__int64)return_longValue;
    LOGI("@@JNI  callbyJNIlong11  return jlong : %ld", clongValue_return);

    return return_longValue;

}



JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_longStaticNvMethod00
        (JNIEnv *env, jclass jcla) {

    jfieldID fid = (*env)->GetStaticFieldID(env, jcla, "longStaticValue", "J");
    jlong jlongValue = (*env)->GetStaticLongField(env, jcla, fid);  // 获得 静态long属性

    __int64 c_longValue = (__int64) jlongValue;
    LOGI("Jni.c@@ longStaticNvMethod00  called  longStaticValue is: %ld",c_longValue);
    (*env)->SetStaticLongField(env, jcla, fid, 500000);    // 设置 静态属性

    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticlong00", "()V"); // 指定静态方法
    (*env)->CallStaticVoidMethod(env, jcla, mid);  // 调用返回值为空的静态方法

    return;
}

JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_longStaticNvMethod01
        (JNIEnv *env,jclass jcla, jlong longValue) {


    __int64 clongValue_value = ( __int64 ) longValue;

    LOGI("Jni.c@@ longStaticNvMethod01  called  param long is: %ld",clongValue_value);

    clongValue_value = clongValue_value + 9876;
    jlong  jlongValue = (jlong)clongValue_value;

    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticlong01", "(J)V");
    (*env)->CallStaticVoidMethod(env, jcla, mid, jlongValue);  // 调用返回值为空的静态方法

    return;
}


JNIEXPORT jlong JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_longStaticNvMethod10
        (JNIEnv *env, jclass jcla) {


    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticlong10", "()J");
    jlong mReturnlongValue =  (*env)->CallStaticLongMethod(env, jcla, mid);  // 调用返回值为空的静态方法

    __int64 clongValue_value = (__int64) mReturnlongValue;
    LOGI("@@JNI  callbyJNIStaticlong10 return  jlong is :   %ld", clongValue_value);

    clongValue_value = clongValue_value + 54321;


    jlong  jlongValue = (jlong) clongValue_value;


    return jlongValue;
}

JNIEXPORT jlong JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_longStaticNvMethod11
        (JNIEnv *env, jclass jcla, jlong longValue) {


    __int64 clongValue = (__int64) longValue;  // jlong 转为 C语言 long 类型
    LOGI("@@JNI  callbyJNIStaticlong11 param  jlong is :   %ld", clongValue);

    clongValue = clongValue + 12345;


    jlong long_jValue = (jlong) clongValue;

    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticlong11", "(J)J");
    jlong mReturnlongValue =  (*env)->CallStaticLongMethod(env, jcla , mid , long_jValue);  //  调用 java的静态方法
    clongValue = (__int64)mReturnlongValue;
    LOGI("@@JNI  callbyJNIStaticlong11 return result  jlong is :   %ld", clongValue);

    return mReturnlongValue;
}
/************************************Long-End*************************************/


/************************************float_Begin*************************************/
// 静态方法和对象方法的不同就在于
// 实例对象方法JNI方法的第二个参数为 jobject(JNIEnv *env, jobject jobj)
// 静态方法 JNI方法 第二个参数为 jclass   (JNIEnv *env, jclass jcls);
JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_floatNvMethod00
        (JNIEnv *env, jobject jobj) {

    jclass jcla = (*env)->GetObjectClass(env, jobj);

    jfieldID fid = (*env)->GetFieldID(env, jcla, "floatValue", "F");


    jfloat jfloatValue = (*env)->GetFloatField(env, jobj, fid);


    float i = (float) jfloatValue;

    LOGI("@@JNI floatNvMethod00 get jfieldID floatValue is :   %f", i);


    (*env)->SetFloatField(env, jobj, fid, 1234.1234);  // 在JNI中设置 java 层floatValue新的值

    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIfloat00", "()V");
    (*env)->CallVoidMethod(env, jobj, mid); // 调用 Java的Object 函数   void callbyJNIfloat00()

    return;
}


JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_floatNvMethod01
        (JNIEnv *env, jobject jobj, jfloat floatValue) {

    jclass jcla = (*env)->GetObjectClass(env, jobj);
    float cfloatValue = (float)floatValue;  // jfloat 强转为 C语言 float 类型

    LOGI("@@JNI  floatNvMethod01 param jfloat is :   %f", cfloatValue);

    cfloatValue =  cfloatValue + 100;

    jfloat new_floatValue =(jfloat)cfloatValue;
    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIfloat01", "(F)V");
    (*env)->CallVoidMethod(env, jobj, mid,new_floatValue); // 调用 Java的Object 函数   void callbyJNIfloat00()
    return;
}



JNIEXPORT jfloat JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_floatNvMethod10
        (JNIEnv *env, jobject jobj) {
    jclass jcla = (*env)->GetObjectClass(env, jobj);

    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIfloat10", "()F");
    jfloat jfloatValue = (*env)->CallFloatMethod(env, jobj, mid);
    float cfloatvalue = (float)jfloatValue;  // jfloat 转为 C语言 float 类型

    LOGI("@@JNI  callbyJNIfloat10 return  jfloat is :   %f", cfloatvalue);
    cfloatvalue = cfloatvalue + 200;

    jfloat result_floatValue = (jfloat)  cfloatvalue;


    return result_floatValue;
}


JNIEXPORT jfloat  JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_floatNvMethod11
        (JNIEnv *env, jobject jobj, jfloat floatValue) {


    jclass jcla = (*env)->GetObjectClass(env, jobj);
    float cfloatValue = (float)floatValue;  // jfloat 强转为 C语言 float 类型

    LOGI("@@JNI  callbyJNIfloat11 params  jfloat is :   %f", cfloatValue);

    cfloatValue = cfloatValue + 300;

    jfloat  jfloat_result = (jfloat)cfloatValue;
    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIfloat11", "(F)F");

    jfloat return_floatValue = (*env)->CallFloatMethod(env, jobj, mid,jfloat_result);

    float cfloatValue_return = (float)return_floatValue;
    LOGI("@@JNI  callbyJNIfloat11  return jfloat : %f", cfloatValue_return);

    return return_floatValue;

}



JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_floatStaticNvMethod00
        (JNIEnv *env, jclass jcla) {

    jfieldID fid = (*env)->GetStaticFieldID(env, jcla, "floatStaticValue", "F");
    jfloat jfloatValue = (*env)->GetStaticFloatField(env, jcla, fid);  // 获得 静态float属性

    float c_floatValue = (float) jfloatValue;
    LOGI("Jni.c@@ floatStaticNvMethod00  called  floatStaticValue is: %f",c_floatValue);
    (*env)->SetStaticFloatField(env, jcla, fid, 500.005);    // 设置 静态属性

    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticfloat00", "()V"); // 指定静态方法
    (*env)->CallStaticVoidMethod(env, jcla, mid);  // 调用返回值为空的静态方法

    return;
}

JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_floatStaticNvMethod01
        (JNIEnv *env,jclass jcla, jfloat floatValue) {


    float cfloatValue_value = ( float ) floatValue;

    LOGI("Jni.c@@ floatStaticNvMethod01  called  param float is: %f",cfloatValue_value);

    cfloatValue_value = cfloatValue_value + 1;
    jfloat  jfloatValue = (jfloat)cfloatValue_value;

    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticfloat01", "(F)V");
    (*env)->CallStaticVoidMethod(env, jcla, mid, jfloatValue);  // 调用返回值为空的静态方法

    return;
}


JNIEXPORT jfloat JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_floatStaticNvMethod10
        (JNIEnv *env, jclass jcla) {


    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticfloat10", "()F");
    jfloat mReturnfloatValue =  (*env)->CallStaticFloatMethod(env, jcla, mid);  // 调用返回值为空的静态方法

    float cfloatValue_value = (float) mReturnfloatValue;
    LOGI("@@JNI  callbyJNIStaticfloat10 return  jfloat is :   %f", cfloatValue_value);

    cfloatValue_value = cfloatValue_value + 11;


    jfloat  jfloatValue = (jfloat) cfloatValue_value;


    return jfloatValue;
}

JNIEXPORT jfloat JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_floatStaticNvMethod11
        (JNIEnv *env, jclass jcla, jfloat floatValue) {


    float cfloatValue = (float) floatValue;  // jfloat 转为 C语言 float 类型
    LOGI("@@JNI  callbyJNIStaticfloat11 param  jfloat is :   %f", cfloatValue);

    cfloatValue = cfloatValue + 11;


    jfloat float_jValue = (jfloat) cfloatValue;

    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticfloat11", "(F)F");
    jfloat mReturnfloatValue =  (*env)->CallStaticFloatMethod(env, jcla , mid , float_jValue);  //  调用 java的静态方法
    cfloatValue = (float)mReturnfloatValue;
    LOGI("@@JNI  callbyJNIStaticfloat11 return result  jfloat is :   %f", cfloatValue);

    return mReturnfloatValue;
}
/************************************Float-End*************************************/

/************************************double_Begin*************************************/
// 静态方法和对象方法的不同就在于
// 实例对象方法JNI方法的第二个参数为 jobject(JNIEnv *env, jobject jobj)
// 静态方法 JNI方法 第二个参数为 jclass   (JNIEnv *env, jclass jcls);
JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_doubleNvMethod00
        (JNIEnv *env, jobject jobj) {

    jclass jcla = (*env)->GetObjectClass(env, jobj);

    jfieldID fid = (*env)->GetFieldID(env, jcla, "doubleValue", "D");


    jdouble jdoubleValue = (*env)->GetDoubleField(env, jobj, fid);


    double i = (double) jdoubleValue;

    LOGI("@@JNI doubleNvMethod00 get jfieldID doubleValue is :   %f", i);


    (*env)->SetDoubleField(env, jobj, fid, 1234.1234);  // 在JNI中设置 java 层doubleValue新的值

    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIdouble00", "()V");
    (*env)->CallVoidMethod(env, jobj, mid); // 调用 Java的Object 函数   void callbyJNIdouble00()

    return;
}


JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_doubleNvMethod01
        (JNIEnv *env, jobject jobj, jdouble doubleValue) {

    jclass jcla = (*env)->GetObjectClass(env, jobj);
    double cdoubleValue = (double)doubleValue;  // jdouble 强转为 C语言 double 类型

    LOGI("@@JNI  doubleNvMethod01 param jdouble is :   %f", cdoubleValue);

    cdoubleValue =  cdoubleValue + 100;

    jdouble new_doubleValue =(jdouble)cdoubleValue;
    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIdouble01", "(D)V");
    (*env)->CallVoidMethod(env, jobj, mid,new_doubleValue); // 调用 Java的Object 函数   void callbyJNIdouble00()
    return;
}



JNIEXPORT jdouble JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_doubleNvMethod10
        (JNIEnv *env, jobject jobj) {
    jclass jcla = (*env)->GetObjectClass(env, jobj);

    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIdouble10", "()D");
    jdouble jdoubleValue = (*env)->CallDoubleMethod(env, jobj, mid);
    double cdoublevalue = (double)jdoubleValue;  // jdouble 转为 C语言 double 类型

    LOGI("@@JNI  callbyJNIdouble10 return  jdouble is :   %f", cdoublevalue);
    cdoublevalue = cdoublevalue + 200;

    jdouble result_doubleValue = (jdouble)  cdoublevalue;


    return result_doubleValue;
}


JNIEXPORT jdouble  JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_doubleNvMethod11
        (JNIEnv *env, jobject jobj, jdouble doubleValue) {


    jclass jcla = (*env)->GetObjectClass(env, jobj);
    double cdoubleValue = (double)doubleValue;  // jdouble 强转为 C语言 double 类型

    LOGI("@@JNI  callbyJNIdouble11 params  jdouble is :   %d", cdoubleValue);

    cdoubleValue = cdoubleValue + 300;

    jdouble  jdouble_result = (jdouble)cdoubleValue;
    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIdouble11", "(D)D");

    jdouble return_doubleValue = (*env)->CallDoubleMethod(env, jobj, mid,jdouble_result);

    double cdoubleValue_return = (double)return_doubleValue;
    LOGI("@@JNI  callbyJNIdouble11  return jdouble : %f", cdoubleValue_return);

    return return_doubleValue;

}



JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_doubleStaticNvMethod00
        (JNIEnv *env, jclass jcla) {

    jfieldID fid = (*env)->GetStaticFieldID(env, jcla, "doubleStaticValue", "D");
    jdouble jdoubleValue = (*env)->GetStaticDoubleField(env, jcla, fid);  // 获得 静态double属性

    double c_doubleValue = (double) jdoubleValue;
    LOGI("Jni.c@@ doubleStaticNvMethod00  called  doubleStaticValue is: %f",c_doubleValue);
    (*env)->SetStaticDoubleField(env, jcla, fid, 500.005);    // 设置 静态属性

    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticdouble00", "()V"); // 指定静态方法
    (*env)->CallStaticVoidMethod(env, jcla, mid);  // 调用返回值为空的静态方法

    return;
}

JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_doubleStaticNvMethod01
        (JNIEnv *env,jclass jcla, jdouble doubleValue) {


    double cdoubleValue_value = ( double ) doubleValue;

    LOGI("Jni.c@@ doubleStaticNvMethod01  called  param double is: %f",cdoubleValue_value);

    cdoubleValue_value = cdoubleValue_value + 1;
    jdouble  jdoubleValue = (jdouble)cdoubleValue_value;

    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticdouble01", "(D)V");
    (*env)->CallStaticVoidMethod(env, jcla, mid, jdoubleValue);  // 调用返回值为空的静态方法

    return;
}


JNIEXPORT jdouble JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_doubleStaticNvMethod10
        (JNIEnv *env, jclass jcla) {


    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticdouble10", "()D");
    jdouble mReturndoubleValue =  (*env)->CallStaticDoubleMethod(env, jcla, mid);  // 调用返回值为空的静态方法

    double cdoubleValue_value = (double) mReturndoubleValue;
    LOGI("@@JNI  callbyJNIStaticdouble10 return  jdouble is :   %f", cdoubleValue_value);

    cdoubleValue_value = cdoubleValue_value + 11;


    jdouble  jdoubleValue = (jdouble) cdoubleValue_value;


    return jdoubleValue;
}

JNIEXPORT jdouble JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_doubleStaticNvMethod11
        (JNIEnv *env, jclass jcla, jdouble doubleValue) {


    double cdoubleValue = (double) doubleValue;  // jdouble 转为 C语言 double 类型
    LOGI("@@JNI  callbyJNIStaticdouble11 param  jdouble is :   %f", cdoubleValue);

    cdoubleValue = cdoubleValue + 11;


    jdouble double_jValue = (jdouble) cdoubleValue;

    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticdouble11", "(D)D");
    jdouble mReturndoubleValue =  (*env)->CallStaticDoubleMethod(env, jcla , mid , double_jValue);  //  调用 java的静态方法
    cdoubleValue = (double)mReturndoubleValue;
    LOGI("@@JNI  callbyJNIStaticdouble11 return result  jdouble is :   %f", cdoubleValue);

    return mReturndoubleValue;
}
/************************************Double-End*************************************/



/************************************String_Begin*************************************/
// 静态方法和对象方法的不同就在于
// 实例对象方法JNI方法的第二个参数为 jobject(JNIEnv *env, jobject jobj)
// 静态方法 JNI方法 第二个参数为 jclass   (JNIEnv *env, jclass jcls);
JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_stringNvMethod00
        (JNIEnv *env, jobject jobj) {

    jclass jcla = (*env)->GetObjectClass(env, jobj);

    jfieldID fid = (*env)->GetFieldID(env, jcla, "stringValue", "Ljava/lang/String;");


    jstring jstr = (*env)->GetObjectField(env, jobj, fid);

    char *c_str = (*env)->GetStringUTFChars(env, jstr, 0);  // 读取到 stringValue的值
    LOGI("@@JNI get jfieldID stringValue is :   %s", c_str);
    jstring new_str = (*env)->NewStringUTF(env, "JNIValue");

    (*env)->SetObjectField(env, jobj, fid, new_str);  // 设置 stringValue新的值

    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIString00", "()V");
    (*env)->CallVoidMethod(env, jobj, mid); // 调用 Java的Object 函数   void callbyJNIString00()

    return;
}


JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_stringNvMethod01
        (JNIEnv *env, jobject jobj, jstring str) {

    jclass jcla = (*env)->GetObjectClass(env, jobj);
    const char *cStr = (*env)->GetStringUTFChars(env, str, 0);  // jstring 转为 C语言 char* 类型

    LOGI("@@JNI  param jstring is :   %s", cStr);

    char *mChar = "<C>";
    char *result = (char *) malloc(strlen(cStr) + strlen(mChar) + 1);
    if (result == NULL)
        return ;
    strcpy(result,  cStr);
    strcat(result,mChar );   // 完成字符的拼接

    jstring new_str = (*env)->NewStringUTF(env, result);
    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIString01", "(Ljava/lang/String;)V");
    (*env)->CallVoidMethod(env, jobj, mid,new_str); // 调用 Java的Object 函数   void callbyJNIString00()
    return;
}


/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    stringNvMethod
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_stringNvMethod10
        (JNIEnv *env, jobject jobj) {
    jclass jcla = (*env)->GetObjectClass(env, jobj);


    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIString10", "()Ljava/lang/String;");
    jstring return_str = (*env)->CallObjectMethod(env, jobj, mid);
    const char *cStr = (*env)->GetStringUTFChars(env, return_str, 0);  // jstring 转为 C语言 char* 类型

    LOGI("@@JNI  callbyJNIString10 return  jstring is :   %s", cStr);

    char *cStr1 ="<C>";

    char *result = (char *) malloc(strlen(cStr) + strlen(cStr1) + 1);
    if (result == NULL)
        return NULL;
    strcpy(result, cStr);
    strcat(result, cStr1);   // 完成字符的拼接
    jstring result_str = (*env)->NewStringUTF(env, result);

    //return (*env)->NewStringUTF(env, return_str); // ▲ 为什么会报错  尼玛 忘了 第二个参数是 C字符  不是 jstring
    //return (*env)->NewStringUTF(env, result_str);         // ▲ 为什么会报错   尼玛 忘了 第二个参数是 C字符  不是 jstring
    //return (*env)->NewStringUTF(env, "OK");
    return result_str;
}


JNIEXPORT jstring  JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_stringNvMethod11
        (JNIEnv *env, jobject jobj, jstring str) {
    const char *cStr = (*env)->GetStringUTFChars(env, str, 0);  // jstring 转为 C语言 char* 类型
    LOGI("@@JNI  callbyJNIString11 params  jstring is :   %s", cStr);
    char *mChar = "<C>";


    char *result = (char *) malloc(strlen(cStr) + strlen(mChar) + 1);
    if (result == NULL)
        return NULL;
    strcpy(result, cStr);
    strcat(result, mChar);   // 完成字符的拼接
    jstring  jstring_result = (*env)->NewStringUTF(env, result);

    jclass jcla = (*env)->GetObjectClass(env, jobj);
    jmethodID mid = (*env)->GetMethodID(env, jcla, "callbyJNIString11", "(Ljava/lang/String;)Ljava/lang/String;");

    jstring return_str = (*env)->CallObjectMethod(env, jobj, mid,jstring_result);
    const char *cStr_return = (*env)->GetStringUTFChars(env, return_str, 0);
    LOGI("@@JNI  callbyJNIString11  return string : %s", cStr_return);

    return return_str;

}



JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_stringStaticNvMethod00
        (JNIEnv *env, jclass jcla) {

    jfieldID fid = (*env)->GetStaticFieldID(env, jcla, "stringStaticValue", "Ljava/lang/String;");
    jstring jstr = (*env)->GetStaticObjectField(env, jcla, fid);  // 获得 静态属性
    char *c_str = (*env)->GetStringUTFChars(env, jstr, 0);
    LOGI("Jni.c@@ stringStaticNvMethod00  called  stringStaticValue is: %s",c_str);
    jstring new_str = (*env)->NewStringUTF(env, "JNIStaticValue");
    (*env)->SetStaticObjectField(env, jcla, fid, new_str);    // 设置 静态属性

    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticString00", "()V"); // 指定静态方法
    (*env)->CallStaticVoidMethod(env, jcla, mid);  // 调用返回值为空的静态方法

    return;
}

JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_stringStaticNvMethod01
        (JNIEnv *env,jclass jcla, jstring str) {


    const char *cstr_value = (*env)->GetStringUTFChars(env, str, 0);

    LOGI("Jni.c@@ stringStaticNvMethod01  called  param string is: %s",cstr_value);

    char *c_str1  ="<C>";

    char *result = (char *) malloc(strlen(cstr_value) + strlen(c_str1) + 1);
    if (result == NULL)
        return ;
    strcpy(result, cstr_value);
    strcat(result, c_str1);   // 完成字符的拼接
    jstring  jstringValue = (*env)->NewStringUTF(env, result);

    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticString01", "(Ljava/lang/String;)V");
    (*env)->CallStaticVoidMethod(env, jcla, mid, jstringValue);  // 调用返回值为空的静态方法

    return;
}


/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    stringStaticNvMethod
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_stringStaticNvMethod10
        (JNIEnv *env, jclass jcla) {


    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticString10", "()Ljava/lang/String;");
    jstring mReturnStr =  (*env)->CallStaticObjectMethod(env, jcla, mid);  // 调用返回值为空的静态方法

    const char *cstr_value = (*env)->GetStringUTFChars(env, mReturnStr, 0);
    LOGI("@@JNI  callbyJNIStaticString10 return  jstring is :   %s", cstr_value);


    char *c_str1  ="<C>";

    char *result = (char *) malloc(strlen(cstr_value) + strlen(c_str1) + 1);
    if (result == NULL)
        return NULL;
    strcpy(result, cstr_value);
    strcat(result, c_str1);   // 完成字符的拼接
    jstring  jstringValue = (*env)->NewStringUTF(env, result);


    return jstringValue;
}

JNIEXPORT jstring JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_stringStaticNvMethod11
        (JNIEnv *env, jclass jcla, jstring str) {


    const char *cStr = (*env)->GetStringUTFChars(env, str, 0);  // jstring 转为 C语言 char* 类型
    LOGI("@@JNI  callbyJNIStaticString11 param  jstring is :   %s", cStr);

    char *mChar = "<C>";
    char *result = (char *) malloc(strlen(cStr) + strlen(mChar) + 1);
    if (result == NULL)
        return NULL ;
    strcpy(result, cStr);
    strcat(result, mChar);   // 完成字符的拼接
    jstring txt = (*env)->NewStringUTF(env, result);

    jmethodID mid = (*env)->GetStaticMethodID(env, jcla, "callbyJNIStaticString11", "(Ljava/lang/String;)Ljava/lang/String;");
    jstring mReturnStr =  (*env)->CallStaticObjectMethod(env, jcla , mid , txt);  //  调用 java的静态方法 来完成字符串的 拼接

    const char *txt1 = (*env)->GetStringUTFChars(env, mReturnStr, 0);  // jstring 转为 C语言 char* 类型

    return (*env)->NewStringUTF(env, txt1);
}
/************************************Java-End*************************************/

JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_voidNvMethod
        (JNIEnv *env, jobject obj) {

    return;
};

/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    booleanNvMethod             jboolean flag = JNI_FALSE;  |  jboolean flag = JNI_TRUE;
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_booleanNvMethod
        (JNIEnv *env, jobject obj) {
    jboolean flag = JNI_FALSE;
    return flag;
}

/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    byteNvMethod
 * Signature: ()B
 */
JNIEXPORT jbyte JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_byteNvMethod
        (JNIEnv *env, jobject obj) {
    jbyte mByte = 0x22;
    return mByte;
}

/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    charNvMethod
 * Signature: ()C       // 一个 jchar 是一个无符号16位值  // jchar jca_result[3] = { ‘e’, ‘r’, ‘r’ };
 */
JNIEXPORT jchar JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_charNvMethod
        (JNIEnv *env, jobject obj) {
    jchar mChar = 'Z';
    return mChar;
}

/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    shortNvMethod
 * Signature: ()S
 */
JNIEXPORT jshort JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_shortNvMethod
        (JNIEnv *env, jobject obj) {
    jshort mShort = 255;
    return mShort;
}

/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    intNvMethod
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_intNvMethod
        (JNIEnv *env, jobject obj) {
    jint mInt = 30000;
    return mInt;
}
/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    longNvMethod
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_longNvMethod
        (JNIEnv *env, jobject obj) {
    jlong mlong = 90000000;
    return mlong;
}

/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    floatNvMethod
 * Signature: ()F
 */
JNIEXPORT jfloat JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_floatNvMethod
        (JNIEnv *env, jobject obj) {
    jfloat mfloat = 10.08f;
    return mfloat;
}
/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    doubleNvMethod
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_doubleNvMethod
        (JNIEnv *env, jobject obj) {
    jdouble mdouble = 11.0809086;
    return mdouble;
}
/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    booleanArrayNvMethod
 * Signature: ()[Z
 */
JNIEXPORT jbooleanArray JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_booleanArrayNvMethod
        (JNIEnv *env, jobject obj) {
    jsize size = 10;
    jbooleanArray mBooleanArray = (jbooleanArray) (*env)->NewBooleanArray(env, size);
    if (mBooleanArray == NULL) {
        return NULL;
    }

    jboolean *boolean_ptr = calloc(size, sizeof(jboolean));
    if (boolean_ptr == NULL) {
        return NULL;
    }


    for (int i = 0; i < size; i++) {
        boolean_ptr[i] = i % 2 == 0 ? JNI_FALSE : JNI_TRUE;
    }

    (*env)->SetBooleanArrayRegion(env, mBooleanArray, 0, size, (jboolean *) boolean_ptr);

    free(boolean_ptr);
    return mBooleanArray;
}

/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    byteArrayNvMethod
 * Signature: ()[B
 */
JNIEXPORT jbyteArray JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_byteArrayNvMethod
        (JNIEnv *env, jobject obj) {
    return NULL;
}

/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    charArrayNvMethod
 * Signature: ()[C
 */
JNIEXPORT jcharArray JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_charArrayNvMethod
        (JNIEnv *env, jobject obj) {
    return NULL;
}
/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    shortArrayNvMethod
 * Signature: ()[S
 */
JNIEXPORT jshortArray JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_shortArrayNvMethod
        (JNIEnv *env, jobject obj) {
    return NULL;
}
/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    intArrayNvMethod
 * Signature: ()[I
 */
JNIEXPORT jintArray JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_intArrayNvMethod
        (JNIEnv *env, jobject obj) {
    return NULL;
}

/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    longArrayNvMethod
 * Signature: ()[J
 */
JNIEXPORT jlongArray JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_longArrayNvMethod
        (JNIEnv *env, jobject obj) {
    return NULL;
}

/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    floatArrayNvMethod
 * Signature: ()[F
 */
JNIEXPORT jfloatArray JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_floatArrayNvMethod
        (JNIEnv *env, jobject obj) {
    return NULL;
}

/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    doubleArrayNvMethod
 * Signature: ()[D
 */
JNIEXPORT jdoubleArray JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_doubleArrayNvMethod
        (JNIEnv *env, jobject obj) {
    return NULL;
}

/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    objectNvMethod
 * Signature: ()Ljava/lang/Object;
 */
JNIEXPORT jobject JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_objectNvMethod
        (JNIEnv *env, jobject obj) {
    return NULL;
}


/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    stringListNvMethod
 * Signature: ()Ljava/util/ArrayList;
 */
JNIEXPORT jobject JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_stringListNvMethod
        (JNIEnv *env, jobject obj) {
    return NULL;
}

/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    objectListNvMethod
 * Signature: ()Ljava/util/ArrayList;
 */
JNIEXPORT jobject JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_objectListNvMethod
        (JNIEnv *env, jobject obj) {
    return NULL;
}

/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    stringMapNvMethod
 * Signature: ()Landroid/util/ArrayMap;
 */
JNIEXPORT jobject JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_stringMapNvMethod
        (JNIEnv *env, jobject obj) {
    return NULL;
}

/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    allNvMethod
 * Signature: (ZBCSIJFDLjava/util/ArrayList;Ljava/util/ArrayList;Landroid/util/ArrayMap;)V
 */
JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_allNvMethod
        (JNIEnv *env, jobject obj, jboolean bool, jbyte byte, jchar charValue, jshort shortValue,
         jint intValue, jlong longValue,
         jfloat floatValue, jdouble doubleValue, jobject obj0,
         jobject obj1, jobject obj2) {
    return;
}

/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    voidStaticNvMethod
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_voidStaticNvMethod
        (JNIEnv *env, jobject obj) {
    return;
}
/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    booleanStaticNvMethod
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_booleanStaticNvMethod
        (JNIEnv *env, jobject obj) {
    return NULL;
}

/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    byteStaticNvMethod
 * Signature: ()B
 */
JNIEXPORT jbyte JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_byteStaticNvMethod
        (JNIEnv *env, jobject obj) {
    return NULL;
}
/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    charStaticNvMethod
 * Signature: ()C
 */
JNIEXPORT jchar JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_charStaticNvMethod
        (JNIEnv *env, jobject obj) {
    return NULL;
}
/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    shortStaticNvMethod
 * Signature: ()S
 */
JNIEXPORT jshort JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_shortStaticNvMethod
        (JNIEnv *env, jobject obj) {
    jshort jshort = 100;
    return jshort;
}
/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    intStaticNvMethod
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_intStaticNvMethod
        (JNIEnv *env, jobject obj) {
    jint mjint = 100000;
    return mjint;
}
/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    longStaticNvMethod
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_longStaticNvMethod
        (JNIEnv *env, jobject obj) {
    jlong mjlong = 12345;
    return mjlong;
}
/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    floatStaticNvMethod
 * Signature: ()F
 */
JNIEXPORT jfloat JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_floatStaticNvMethod
        (JNIEnv *env, jobject obj) {
    jfloat mjfloat = 3.14;
    return mjfloat;
}
/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    doubleStaticNvMethod
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_doubleStaticNvMethod
        (JNIEnv *env, jobject obj) {

    jdouble mjdouble = 3.1415926;
    return mjdouble;

}
/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    booleanArrayStaticNvMethod
 * Signature: ()[Z
 */
JNIEXPORT jbooleanArray JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_booleanArrayStaticNvMethod
        (JNIEnv *env, jobject obj) {
    return NULL;
}

/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    byteArrayStaticNvMethod
 * Signature: ()[B
 */
JNIEXPORT jbyteArray JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_byteArrayStaticNvMethod
        (JNIEnv *env, jobject obj) {
    return NULL;
}

/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    charArrayStaticNvMethod
 * Signature: ()[C
 */
JNIEXPORT jcharArray JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_charArrayStaticNvMethod
        (JNIEnv *env, jobject obj) {
    return NULL;
}

/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    shortArrayStaticNvMethod
 * Signature: ()[S
 */
JNIEXPORT jshortArray JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_shortArrayStaticNvMethod
        (JNIEnv *env, jobject obj) {
    return NULL;
}

/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    intArrayStaticNvMethod
 * Signature: ()[I
 */
JNIEXPORT jintArray JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_intArrayStaticNvMethod
        (JNIEnv *env, jobject obj) {
    return NULL;
}

/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    longArrayStaticNvMethod
 * Signature: ()[J
 */
JNIEXPORT jlongArray JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_longArrayStaticNvMethod
        (JNIEnv *env, jobject obj) {
    return NULL;
}

/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    floatArrayStaticNvMethod
 * Signature: ()[F
 */
JNIEXPORT jfloatArray JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_floatArrayStaticNvMethod
        (JNIEnv *env, jobject obj) {
    return NULL;
}

/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    doubleArrayStaticNvMethod
 * Signature: ()[D
 */
JNIEXPORT jdoubleArray JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_doubleArrayStaticNvMethod
        (JNIEnv *env, jobject obj) {
    return NULL;
}

/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    objectStaticNvMethod
 * Signature: ()Ljava/lang/Object;
 */
JNIEXPORT jobject JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_objectStaticNvMethod
        (JNIEnv *env, jobject obj) {
    return NULL;
}








/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    stringListStaticNvMethod
 * Signature: ()Ljava/util/ArrayList;
 */
JNIEXPORT jobject JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_stringListStaticNvMethod
        (JNIEnv *env, jobject obj) {
    return NULL;
}

/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    objectListStaticNvMethod
 * Signature: ()Ljava/util/ArrayList;
*/
JNIEXPORT jobject JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_objectListStaticNvMethod
        (JNIEnv *env, jobject obj) {
    return NULL;
}

/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    stringMapStaticNvMethod
 * Signature: ()Landroid/util/ArrayMap;
 */
JNIEXPORT jobject JNICALL
Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_stringMapStaticNvMethod
        (JNIEnv *env, jobject obj) {
    return NULL;
}

/*
 * Class:     com_zukgit_administrator_testjni_zukgit_JniUtil
 * Method:    allStaticNvMethod
 * Signature: (ZBCSIJFDLjava/util/ArrayList;Ljava/util/ArrayList;Landroid/util/ArrayMap;)V
 */
JNIEXPORT void JNICALL Java_com_zukgit_administrator_testjni_1zukgit_JniUtil_allStaticNvMethod
        (JNIEnv *env, jobject obj, jboolean bool, jbyte byte, jchar charValue, jshort shortValue,
         jint intValue, jlong longValue,
         jfloat floatValue, jdouble doubleValue, jobject obj0,
         jobject obj1, jobject obj2) {
    return;
}