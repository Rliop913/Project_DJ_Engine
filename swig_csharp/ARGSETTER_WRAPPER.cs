//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.4.0
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class ARGSETTER_WRAPPER : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal ARGSETTER_WRAPPER(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(ARGSETTER_WRAPPER obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(ARGSETTER_WRAPPER obj) {
    if (obj != null) {
      if (!obj.swigCMemOwn)
        throw new global::System.ApplicationException("Cannot release ownership as memory is not owned");
      global::System.Runtime.InteropServices.HandleRef ptr = obj.swigCPtr;
      obj.swigCMemOwn = false;
      obj.Dispose();
      return ptr;
    } else {
      return new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
    }
  }

  ~ARGSETTER_WRAPPER() {
    Dispose(false);
  }

  public void Dispose() {
    Dispose(true);
    global::System.GC.SuppressFinalize(this);
  }

  protected virtual void Dispose(bool disposing) {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          pdje_POLYGLOTPINVOKE.delete_ARGSETTER_WRAPPER(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public ARGSETTER_WRAPPER(FXControlPannel pointer) : this(pdje_POLYGLOTPINVOKE.new_ARGSETTER_WRAPPER(FXControlPannel.getCPtr(pointer)), true) {
  }

  public KEY_VEC GetFXArgKeys(FXList fx) {
    KEY_VEC ret = new KEY_VEC(pdje_POLYGLOTPINVOKE.ARGSETTER_WRAPPER_GetFXArgKeys(swigCPtr, (int)fx), true);
    return ret;
  }

  public void SetFXArg(FXList fx, string key, double arg) {
    pdje_POLYGLOTPINVOKE.ARGSETTER_WRAPPER_SetFXArg(swigCPtr, (int)fx, key, arg);
    if (pdje_POLYGLOTPINVOKE.SWIGPendingException.Pending) throw pdje_POLYGLOTPINVOKE.SWIGPendingException.Retrieve();
  }

}
