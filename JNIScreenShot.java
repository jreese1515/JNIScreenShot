
public class JNIScreenShot {  // Save as HelloJNI.java
   static {
      System.loadLibrary("JNIScreenShot"); // Load native library hello.dll (Windows) or libhello.so (Unixes)
                                   //  at runtime
                                   // This library contains a native method called sayHello()
   }
 
   private native void captureScreen(String filePath, int x, int y, int width, int height);
   
   private native int getNumber();

}