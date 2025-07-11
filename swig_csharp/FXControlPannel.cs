//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.4.0
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class FXControlPannel : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal FXControlPannel(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(FXControlPannel obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(FXControlPannel obj) {
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

  ~FXControlPannel() {
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
          pdje_POLYGLOTPINVOKE.delete_FXControlPannel(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public FXControlPannel(int sampleRate) : this(pdje_POLYGLOTPINVOKE.new_FXControlPannel(sampleRate), true) {
  }

  public SWIGTYPE_p_ARGSETTER GetArgSetter(FXList fx) {
    SWIGTYPE_p_ARGSETTER ret = new SWIGTYPE_p_ARGSETTER(pdje_POLYGLOTPINVOKE.FXControlPannel_GetArgSetter(swigCPtr, (int)fx), true);
    return ret;
  }

  public void FX_ON_OFF(FXList fx, bool onoff) {
    pdje_POLYGLOTPINVOKE.FXControlPannel_FX_ON_OFF(swigCPtr, (int)fx, onoff);
  }

  public void addFX(SWIGTYPE_p_p_float pcm, int samples) {
    pdje_POLYGLOTPINVOKE.FXControlPannel_addFX(swigCPtr, SWIGTYPE_p_p_float.getCPtr(pcm), samples);
  }

  public bool checkSomethingOn() {
    bool ret = pdje_POLYGLOTPINVOKE.FXControlPannel_checkSomethingOn(swigCPtr);
    return ret;
  }

}
