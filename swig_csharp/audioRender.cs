//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.3.0
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class audioRender : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal audioRender(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(audioRender obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(audioRender obj) {
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

  ~audioRender() {
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
          pdje_POLYGLOTPINVOKE.delete_audioRender(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public SWIGTYPE_p_std__optionalT_std__vectorT_float_t_t rendered_frames {
    set {
      pdje_POLYGLOTPINVOKE.audioRender_rendered_frames_set(swigCPtr, SWIGTYPE_p_std__optionalT_std__vectorT_float_t_t.getCPtr(value));
      if (pdje_POLYGLOTPINVOKE.SWIGPendingException.Pending) throw pdje_POLYGLOTPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      SWIGTYPE_p_std__optionalT_std__vectorT_float_t_t ret = new SWIGTYPE_p_std__optionalT_std__vectorT_float_t_t(pdje_POLYGLOTPINVOKE.audioRender_rendered_frames_get(swigCPtr), true);
      if (pdje_POLYGLOTPINVOKE.SWIGPendingException.Pending) throw pdje_POLYGLOTPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

  public bool LoadTrack(SWIGTYPE_p_litedb db, SWIGTYPE_p_trackdata td) {
    bool ret = pdje_POLYGLOTPINVOKE.audioRender_LoadTrack(swigCPtr, SWIGTYPE_p_litedb.getCPtr(db), SWIGTYPE_p_trackdata.getCPtr(td));
    if (pdje_POLYGLOTPINVOKE.SWIGPendingException.Pending) throw pdje_POLYGLOTPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public audioRender() : this(pdje_POLYGLOTPINVOKE.new_audioRender(), true) {
  }

}
