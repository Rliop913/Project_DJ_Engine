//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (https://www.swig.org).
// Version 4.3.0
//
// Do not make changes to this file unless you know what you are doing - modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


public class KEY_VEC : global::System.IDisposable, global::System.Collections.IEnumerable, global::System.Collections.Generic.IList<string>
 {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal KEY_VEC(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(KEY_VEC obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  internal static global::System.Runtime.InteropServices.HandleRef swigRelease(KEY_VEC obj) {
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

  ~KEY_VEC() {
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
          pdje_POLYGLOTPINVOKE.delete_KEY_VEC(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
    }
  }

  public KEY_VEC(global::System.Collections.IEnumerable c) : this() {
    if (c == null)
      throw new global::System.ArgumentNullException("c");
    foreach (string element in c) {
      this.Add(element);
    }
  }

  public KEY_VEC(global::System.Collections.Generic.IEnumerable<string> c) : this() {
    if (c == null)
      throw new global::System.ArgumentNullException("c");
    foreach (string element in c) {
      this.Add(element);
    }
  }

  public bool IsFixedSize {
    get {
      return false;
    }
  }

  public bool IsReadOnly {
    get {
      return false;
    }
  }

  public string this[int index]  {
    get {
      return getitem(index);
    }
    set {
      setitem(index, value);
    }
  }

  public int Capacity {
    get {
      return (int)capacity();
    }
    set {
      if (value < 0 || (uint)value < size())
        throw new global::System.ArgumentOutOfRangeException("Capacity");
      reserve((uint)value);
    }
  }

  public bool IsEmpty {
    get {
      return empty();
    }
  }

  public int Count {
    get {
      return (int)size();
    }
  }

  public bool IsSynchronized {
    get {
      return false;
    }
  }

  public void CopyTo(string[] array)
  {
    CopyTo(0, array, 0, this.Count);
  }

  public void CopyTo(string[] array, int arrayIndex)
  {
    CopyTo(0, array, arrayIndex, this.Count);
  }

  public void CopyTo(int index, string[] array, int arrayIndex, int count)
  {
    if (array == null)
      throw new global::System.ArgumentNullException("array");
    if (index < 0)
      throw new global::System.ArgumentOutOfRangeException("index", "Value is less than zero");
    if (arrayIndex < 0)
      throw new global::System.ArgumentOutOfRangeException("arrayIndex", "Value is less than zero");
    if (count < 0)
      throw new global::System.ArgumentOutOfRangeException("count", "Value is less than zero");
    if (array.Rank > 1)
      throw new global::System.ArgumentException("Multi dimensional array.", "array");
    if (index+count > this.Count || arrayIndex+count > array.Length)
      throw new global::System.ArgumentException("Number of elements to copy is too large.");
    for (int i=0; i<count; i++)
      array.SetValue(getitemcopy(index+i), arrayIndex+i);
  }

  public string[] ToArray() {
    string[] array = new string[this.Count];
    this.CopyTo(array);
    return array;
  }

  global::System.Collections.Generic.IEnumerator<string> global::System.Collections.Generic.IEnumerable<string>.GetEnumerator() {
    return new KEY_VECEnumerator(this);
  }

  global::System.Collections.IEnumerator global::System.Collections.IEnumerable.GetEnumerator() {
    return new KEY_VECEnumerator(this);
  }

  public KEY_VECEnumerator GetEnumerator() {
    return new KEY_VECEnumerator(this);
  }

  // Type-safe enumerator
  /// Note that the IEnumerator documentation requires an InvalidOperationException to be thrown
  /// whenever the collection is modified. This has been done for changes in the size of the
  /// collection but not when one of the elements of the collection is modified as it is a bit
  /// tricky to detect unmanaged code that modifies the collection under our feet.
  public sealed class KEY_VECEnumerator : global::System.Collections.IEnumerator
    , global::System.Collections.Generic.IEnumerator<string>
  {
    private KEY_VEC collectionRef;
    private int currentIndex;
    private object currentObject;
    private int currentSize;

    public KEY_VECEnumerator(KEY_VEC collection) {
      collectionRef = collection;
      currentIndex = -1;
      currentObject = null;
      currentSize = collectionRef.Count;
    }

    // Type-safe iterator Current
    public string Current {
      get {
        if (currentIndex == -1)
          throw new global::System.InvalidOperationException("Enumeration not started.");
        if (currentIndex > currentSize - 1)
          throw new global::System.InvalidOperationException("Enumeration finished.");
        if (currentObject == null)
          throw new global::System.InvalidOperationException("Collection modified.");
        return (string)currentObject;
      }
    }

    // Type-unsafe IEnumerator.Current
    object global::System.Collections.IEnumerator.Current {
      get {
        return Current;
      }
    }

    public bool MoveNext() {
      int size = collectionRef.Count;
      bool moveOkay = (currentIndex+1 < size) && (size == currentSize);
      if (moveOkay) {
        currentIndex++;
        currentObject = collectionRef[currentIndex];
      } else {
        currentObject = null;
      }
      return moveOkay;
    }

    public void Reset() {
      currentIndex = -1;
      currentObject = null;
      if (collectionRef.Count != currentSize) {
        throw new global::System.InvalidOperationException("Collection modified.");
      }
    }

    public void Dispose() {
        currentIndex = -1;
        currentObject = null;
    }
  }

  public KEY_VEC() : this(pdje_POLYGLOTPINVOKE.new_KEY_VEC__SWIG_0(), true) {
  }

  public KEY_VEC(KEY_VEC other) : this(pdje_POLYGLOTPINVOKE.new_KEY_VEC__SWIG_1(KEY_VEC.getCPtr(other)), true) {
    if (pdje_POLYGLOTPINVOKE.SWIGPendingException.Pending) throw pdje_POLYGLOTPINVOKE.SWIGPendingException.Retrieve();
  }

  public void Clear() {
    pdje_POLYGLOTPINVOKE.KEY_VEC_Clear(swigCPtr);
  }

  public void Add(string x) {
    pdje_POLYGLOTPINVOKE.KEY_VEC_Add(swigCPtr, x);
    if (pdje_POLYGLOTPINVOKE.SWIGPendingException.Pending) throw pdje_POLYGLOTPINVOKE.SWIGPendingException.Retrieve();
  }

  private uint size() {
    uint ret = pdje_POLYGLOTPINVOKE.KEY_VEC_size(swigCPtr);
    return ret;
  }

  private bool empty() {
    bool ret = pdje_POLYGLOTPINVOKE.KEY_VEC_empty(swigCPtr);
    return ret;
  }

  private uint capacity() {
    uint ret = pdje_POLYGLOTPINVOKE.KEY_VEC_capacity(swigCPtr);
    return ret;
  }

  private void reserve(uint n) {
    pdje_POLYGLOTPINVOKE.KEY_VEC_reserve(swigCPtr, n);
  }

  public KEY_VEC(int capacity) : this(pdje_POLYGLOTPINVOKE.new_KEY_VEC__SWIG_2(capacity), true) {
    if (pdje_POLYGLOTPINVOKE.SWIGPendingException.Pending) throw pdje_POLYGLOTPINVOKE.SWIGPendingException.Retrieve();
  }

  private string getitemcopy(int index) {
    string ret = pdje_POLYGLOTPINVOKE.KEY_VEC_getitemcopy(swigCPtr, index);
    if (pdje_POLYGLOTPINVOKE.SWIGPendingException.Pending) throw pdje_POLYGLOTPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  private string getitem(int index) {
    string ret = pdje_POLYGLOTPINVOKE.KEY_VEC_getitem(swigCPtr, index);
    if (pdje_POLYGLOTPINVOKE.SWIGPendingException.Pending) throw pdje_POLYGLOTPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  private void setitem(int index, string val) {
    pdje_POLYGLOTPINVOKE.KEY_VEC_setitem(swigCPtr, index, val);
    if (pdje_POLYGLOTPINVOKE.SWIGPendingException.Pending) throw pdje_POLYGLOTPINVOKE.SWIGPendingException.Retrieve();
  }

  public void AddRange(KEY_VEC values) {
    pdje_POLYGLOTPINVOKE.KEY_VEC_AddRange(swigCPtr, KEY_VEC.getCPtr(values));
    if (pdje_POLYGLOTPINVOKE.SWIGPendingException.Pending) throw pdje_POLYGLOTPINVOKE.SWIGPendingException.Retrieve();
  }

  public KEY_VEC GetRange(int index, int count) {
    global::System.IntPtr cPtr = pdje_POLYGLOTPINVOKE.KEY_VEC_GetRange(swigCPtr, index, count);
    KEY_VEC ret = (cPtr == global::System.IntPtr.Zero) ? null : new KEY_VEC(cPtr, true);
    if (pdje_POLYGLOTPINVOKE.SWIGPendingException.Pending) throw pdje_POLYGLOTPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public void Insert(int index, string x) {
    pdje_POLYGLOTPINVOKE.KEY_VEC_Insert(swigCPtr, index, x);
    if (pdje_POLYGLOTPINVOKE.SWIGPendingException.Pending) throw pdje_POLYGLOTPINVOKE.SWIGPendingException.Retrieve();
  }

  public void InsertRange(int index, KEY_VEC values) {
    pdje_POLYGLOTPINVOKE.KEY_VEC_InsertRange(swigCPtr, index, KEY_VEC.getCPtr(values));
    if (pdje_POLYGLOTPINVOKE.SWIGPendingException.Pending) throw pdje_POLYGLOTPINVOKE.SWIGPendingException.Retrieve();
  }

  public void RemoveAt(int index) {
    pdje_POLYGLOTPINVOKE.KEY_VEC_RemoveAt(swigCPtr, index);
    if (pdje_POLYGLOTPINVOKE.SWIGPendingException.Pending) throw pdje_POLYGLOTPINVOKE.SWIGPendingException.Retrieve();
  }

  public void RemoveRange(int index, int count) {
    pdje_POLYGLOTPINVOKE.KEY_VEC_RemoveRange(swigCPtr, index, count);
    if (pdje_POLYGLOTPINVOKE.SWIGPendingException.Pending) throw pdje_POLYGLOTPINVOKE.SWIGPendingException.Retrieve();
  }

  public static KEY_VEC Repeat(string value, int count) {
    global::System.IntPtr cPtr = pdje_POLYGLOTPINVOKE.KEY_VEC_Repeat(value, count);
    KEY_VEC ret = (cPtr == global::System.IntPtr.Zero) ? null : new KEY_VEC(cPtr, true);
    if (pdje_POLYGLOTPINVOKE.SWIGPendingException.Pending) throw pdje_POLYGLOTPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public void Reverse() {
    pdje_POLYGLOTPINVOKE.KEY_VEC_Reverse__SWIG_0(swigCPtr);
  }

  public void Reverse(int index, int count) {
    pdje_POLYGLOTPINVOKE.KEY_VEC_Reverse__SWIG_1(swigCPtr, index, count);
    if (pdje_POLYGLOTPINVOKE.SWIGPendingException.Pending) throw pdje_POLYGLOTPINVOKE.SWIGPendingException.Retrieve();
  }

  public void SetRange(int index, KEY_VEC values) {
    pdje_POLYGLOTPINVOKE.KEY_VEC_SetRange(swigCPtr, index, KEY_VEC.getCPtr(values));
    if (pdje_POLYGLOTPINVOKE.SWIGPendingException.Pending) throw pdje_POLYGLOTPINVOKE.SWIGPendingException.Retrieve();
  }

  public bool Contains(string value) {
    bool ret = pdje_POLYGLOTPINVOKE.KEY_VEC_Contains(swigCPtr, value);
    if (pdje_POLYGLOTPINVOKE.SWIGPendingException.Pending) throw pdje_POLYGLOTPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int IndexOf(string value) {
    int ret = pdje_POLYGLOTPINVOKE.KEY_VEC_IndexOf(swigCPtr, value);
    if (pdje_POLYGLOTPINVOKE.SWIGPendingException.Pending) throw pdje_POLYGLOTPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public int LastIndexOf(string value) {
    int ret = pdje_POLYGLOTPINVOKE.KEY_VEC_LastIndexOf(swigCPtr, value);
    if (pdje_POLYGLOTPINVOKE.SWIGPendingException.Pending) throw pdje_POLYGLOTPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public bool Remove(string value) {
    bool ret = pdje_POLYGLOTPINVOKE.KEY_VEC_Remove(swigCPtr, value);
    if (pdje_POLYGLOTPINVOKE.SWIGPendingException.Pending) throw pdje_POLYGLOTPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

}
