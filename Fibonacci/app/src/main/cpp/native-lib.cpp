#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_meoagency_android_fibonacci_MainActivity_stringFromJNI(JNIEnv *env, jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

long fibN(long n) {
    if(n<=0) return 0;
    if(n==1) return 1;
    return fibN(n-1) + fibN(n-2);
}

long fibNI(long n) {
    long previous = -1;
    long result = 1;
    long i=0;
    int sum=0;
    for (i = 0; i <= n; i++) {
        sum = result + previous;
        previous = result;
        result = sum;
    }
    return result;
}

extern "C"
JNIEXPORT jlong JNICALL
Java_com_meoagency_android_fibonacci_MainActivity_00024FibLib_fibN(JNIEnv *env, jclass type, jlong n) {
    return fibN(n);
}extern "C"
JNIEXPORT jlong JNICALL
Java_com_meoagency_android_fibonacci_MainActivity_00024FibLib_fibNI__J(JNIEnv *env, jclass type, jlong n) {
    return fibNI(n);
}