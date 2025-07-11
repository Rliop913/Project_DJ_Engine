# This file was automatically generated by SWIG (https://www.swig.org).
# Version 4.4.0
#
# Do not make changes to this file unless you know what you are doing - modify
# the SWIG interface file instead.

from sys import version_info as _swig_python_version_info
# Import the low-level C/C++ module
if getattr(globals().get("__spec__"), "parent", None) or __package__ or "." in __name__:
    from . import _pdje_python
else:
    import _pdje_python

try:
    import builtins as __builtin__
except ImportError:
    import __builtin__

def _swig_repr(self):
    try:
        strthis = "proxy of " + self.this.__repr__()
    except __builtin__.Exception:
        strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)


def _swig_setattr_nondynamic_instance_variable(set):
    def set_instance_attr(self, name, value):
        if name == "this":
            set(self, name, value)
        elif name == "thisown":
            self.this.own(value)
        elif hasattr(self, name) and isinstance(getattr(type(self), name), property):
            set(self, name, value)
        else:
            raise AttributeError("You cannot add instance attributes to %s" % self)
    return set_instance_attr


def _swig_setattr_nondynamic_class_variable(set):
    def set_class_attr(cls, name, value):
        if hasattr(cls, name) and not isinstance(getattr(cls, name), property):
            set(cls, name, value)
        else:
            raise AttributeError("You cannot add class attributes to %s" % cls)
    return set_class_attr


def _swig_add_metaclass(metaclass):
    """Class decorator for adding a metaclass to a SWIG wrapped class - a slimmed down version of six.add_metaclass"""
    def wrapper(cls):
        return metaclass(cls.__name__, cls.__bases__, cls.__dict__.copy())
    return wrapper


class _SwigNonDynamicMeta(type):
    """Meta class to enforce nondynamic attributes (no new attributes) for a class"""
    __setattr__ = _swig_setattr_nondynamic_class_variable(type.__setattr__)


class SwigPyIterator(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")

    def __init__(self, *args, **kwargs):
        raise AttributeError("No constructor defined - class is abstract")
    __repr__ = _swig_repr
    __swig_destroy__ = _pdje_python.delete_SwigPyIterator

    def value(self):
        return _pdje_python.SwigPyIterator_value(self)

    def incr(self, n=1):
        return _pdje_python.SwigPyIterator_incr(self, n)

    def decr(self, n=1):
        return _pdje_python.SwigPyIterator_decr(self, n)

    def distance(self, x):
        return _pdje_python.SwigPyIterator_distance(self, x)

    def equal(self, x):
        return _pdje_python.SwigPyIterator_equal(self, x)

    def copy(self):
        return _pdje_python.SwigPyIterator_copy(self)

    def next(self):
        return _pdje_python.SwigPyIterator_next(self)

    def __next__(self):
        return _pdje_python.SwigPyIterator___next__(self)

    def previous(self):
        return _pdje_python.SwigPyIterator_previous(self)

    def advance(self, n):
        return _pdje_python.SwigPyIterator_advance(self, n)

    def __eq__(self, x):
        return _pdje_python.SwigPyIterator___eq__(self, x)

    def __ne__(self, x):
        return _pdje_python.SwigPyIterator___ne__(self, x)

    def __iadd__(self, n):
        return _pdje_python.SwigPyIterator___iadd__(self, n)

    def __isub__(self, n):
        return _pdje_python.SwigPyIterator___isub__(self, n)

    def __add__(self, n):
        return _pdje_python.SwigPyIterator___add__(self, n)

    def __sub__(self, *args):
        return _pdje_python.SwigPyIterator___sub__(self, *args)
    def __iter__(self):
        return self

# Register SwigPyIterator in _pdje_python:
_pdje_python.SwigPyIterator_swigregister(SwigPyIterator)
SHARED_PTR_DISOWN = _pdje_python.SHARED_PTR_DISOWN
COMPRESSOR = _pdje_python.COMPRESSOR
DISTORTION = _pdje_python.DISTORTION
ECHO = _pdje_python.ECHO
EQ = _pdje_python.EQ
FILTER = _pdje_python.FILTER
FLANGER = _pdje_python.FLANGER
OCSFILTER = _pdje_python.OCSFILTER
PANNER = _pdje_python.PANNER
PHASER = _pdje_python.PHASER
ROBOT = _pdje_python.ROBOT
ROLL = _pdje_python.ROLL
TRANCE = _pdje_python.TRANCE
VOL = _pdje_python.VOL
class FXControlPannel(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")
    __repr__ = _swig_repr

    def __init__(self, sampleRate):
        _pdje_python.FXControlPannel_swiginit(self, _pdje_python.new_FXControlPannel(sampleRate))

    def GetArgSetter(self, fx):
        return _pdje_python.FXControlPannel_GetArgSetter(self, fx)

    def FX_ON_OFF(self, fx, onoff):
        return _pdje_python.FXControlPannel_FX_ON_OFF(self, fx, onoff)

    def addFX(self, pcm, samples):
        return _pdje_python.FXControlPannel_addFX(self, pcm, samples)

    def checkSomethingOn(self):
        return _pdje_python.FXControlPannel_checkSomethingOn(self)
    __swig_destroy__ = _pdje_python.delete_FXControlPannel

# Register FXControlPannel in _pdje_python:
_pdje_python.FXControlPannel_swigregister(FXControlPannel)

def toFaustStylePCM(faustPCM, _in, frameCount):
    return _pdje_python.toFaustStylePCM(faustPCM, _in, frameCount)

def toLRStylePCM(faustPCM, out, frameCount):
    return _pdje_python.toLRStylePCM(faustPCM, out, frameCount)
FULL_PRE_RENDER = _pdje_python.FULL_PRE_RENDER
HYBRID_RENDER = _pdje_python.HYBRID_RENDER
FULL_MANUAL_RENDER = _pdje_python.FULL_MANUAL_RENDER
class PDJE(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")
    __repr__ = _swig_repr
    DBROOT = property(_pdje_python.PDJE_DBROOT_get, _pdje_python.PDJE_DBROOT_set)

    def __init__(self, rootDir):
        _pdje_python.PDJE_swiginit(self, _pdje_python.new_PDJE(rootDir))
    __swig_destroy__ = _pdje_python.delete_PDJE
    player = property(_pdje_python.PDJE_player_get, _pdje_python.PDJE_player_set)
    editor = property(_pdje_python.PDJE_editor_get, _pdje_python.PDJE_editor_set)

    def InitPlayer(self, mode, td, FrameBufferSize):
        return _pdje_python.PDJE_InitPlayer(self, mode, td, FrameBufferSize)

    def InitEditor(self, auth_name, auth_email, projectRoot):
        return _pdje_python.PDJE_InitEditor(self, auth_name, auth_email, projectRoot)

    def GetNoteObjects(self, td, ObjectSetCallback):
        return _pdje_python.PDJE_GetNoteObjects(self, td, ObjectSetCallback)

    def SearchMusic(self, Title, composer, bpm=-1):
        return _pdje_python.PDJE_SearchMusic(self, Title, composer, bpm)

    def SearchTrack(self, Title):
        return _pdje_python.PDJE_SearchTrack(self, Title)

    def GetPlayerObject(self):
        return _pdje_python.PDJE_GetPlayerObject(self)

# Register PDJE in _pdje_python:
_pdje_python.PDJE_swigregister(PDJE)
class ARGSETTER_WRAPPER(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")
    __repr__ = _swig_repr

    def __init__(self, pointer):
        _pdje_python.ARGSETTER_WRAPPER_swiginit(self, _pdje_python.new_ARGSETTER_WRAPPER(pointer))
    __swig_destroy__ = _pdje_python.delete_ARGSETTER_WRAPPER

    def GetFXArgKeys(self, fx):
        return _pdje_python.ARGSETTER_WRAPPER_GetFXArgKeys(self, fx)

    def SetFXArg(self, fx, key, arg):
        return _pdje_python.ARGSETTER_WRAPPER_SetFXArg(self, fx, key, arg)

# Register ARGSETTER_WRAPPER in _pdje_python:
_pdje_python.ARGSETTER_WRAPPER_swigregister(ARGSETTER_WRAPPER)
class litedb(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")
    __repr__ = _swig_repr
    DB_ERROR = property(_pdje_python.litedb_DB_ERROR_get, _pdje_python.litedb_DB_ERROR_set)

    def KVGet(self, K, V):
        return _pdje_python.litedb_KVGet(self, K, V)

    def KVPut(self, K, V):
        return _pdje_python.litedb_KVPut(self, K, V)

    def openDB(self, dbPath):
        return _pdje_python.litedb_openDB(self, dbPath)

    def getRoot(self):
        return _pdje_python.litedb_getRoot(self)

    def __init__(self):
        _pdje_python.litedb_swiginit(self, _pdje_python.new_litedb())
    __swig_destroy__ = _pdje_python.delete_litedb

# Register litedb in _pdje_python:
_pdje_python.litedb_swigregister(litedb)
class musdata(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")
    __repr__ = _swig_repr
    title = property(_pdje_python.musdata_title_get, _pdje_python.musdata_title_set)
    composer = property(_pdje_python.musdata_composer_get, _pdje_python.musdata_composer_set)
    musicPath = property(_pdje_python.musdata_musicPath_get, _pdje_python.musdata_musicPath_set)
    bpmBinary = property(_pdje_python.musdata_bpmBinary_get, _pdje_python.musdata_bpmBinary_set)
    bpm = property(_pdje_python.musdata_bpm_get, _pdje_python.musdata_bpm_set)
    firstBar = property(_pdje_python.musdata_firstBar_get, _pdje_python.musdata_firstBar_set)

    def __init__(self, *args):
        _pdje_python.musdata_swiginit(self, _pdje_python.new_musdata(*args))

    def GenSearchSTMT(self, dbstate, db):
        return _pdje_python.musdata_GenSearchSTMT(self, dbstate, db)

    def GenInsertSTMT(self, dbstate, db):
        return _pdje_python.musdata_GenInsertSTMT(self, dbstate, db)

    def GenEditSTMT(self, dbstate, db, toEdit):
        return _pdje_python.musdata_GenEditSTMT(self, dbstate, db, toEdit)

    def GenDeleteSTMT(self, dbstate, db):
        return _pdje_python.musdata_GenDeleteSTMT(self, dbstate, db)
    __swig_destroy__ = _pdje_python.delete_musdata

# Register musdata in _pdje_python:
_pdje_python.musdata_swigregister(musdata)
class trackdata(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")
    __repr__ = _swig_repr
    trackTitle = property(_pdje_python.trackdata_trackTitle_get, _pdje_python.trackdata_trackTitle_set)
    mixBinary = property(_pdje_python.trackdata_mixBinary_get, _pdje_python.trackdata_mixBinary_set)
    noteBinary = property(_pdje_python.trackdata_noteBinary_get, _pdje_python.trackdata_noteBinary_set)
    cachedMixList = property(_pdje_python.trackdata_cachedMixList_get, _pdje_python.trackdata_cachedMixList_set)

    def __init__(self, *args):
        _pdje_python.trackdata_swiginit(self, _pdje_python.new_trackdata(*args))

    def GenSearchSTMT(self, dbstate, db):
        return _pdje_python.trackdata_GenSearchSTMT(self, dbstate, db)

    def GenInsertSTMT(self, dbstate, db):
        return _pdje_python.trackdata_GenInsertSTMT(self, dbstate, db)

    def GenEditSTMT(self, dbstate, db, toEdit):
        return _pdje_python.trackdata_GenEditSTMT(self, dbstate, db, toEdit)

    def GenDeleteSTMT(self, dbstate, db):
        return _pdje_python.trackdata_GenDeleteSTMT(self, dbstate, db)
    __swig_destroy__ = _pdje_python.delete_trackdata

# Register trackdata in _pdje_python:
_pdje_python.trackdata_swigregister(trackdata)
class audioPlayer(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")
    __repr__ = _swig_repr
    STATUS = property(_pdje_python.audioPlayer_STATUS_get, _pdje_python.audioPlayer_STATUS_set)

    def GetStatus(self):
        return _pdje_python.audioPlayer_GetStatus(self)

    def Activate(self):
        return _pdje_python.audioPlayer_Activate(self)

    def Deactivate(self):
        return _pdje_python.audioPlayer_Deactivate(self)

    def ChangeCursorPos(self, pos):
        return _pdje_python.audioPlayer_ChangeCursorPos(self, pos)

    def GetConsumedFrames(self):
        return _pdje_python.audioPlayer_GetConsumedFrames(self)

    def GetFXControlPannel(self, *args):
        return _pdje_python.audioPlayer_GetFXControlPannel(self, *args)

    def GetMusicControlPannel(self):
        return _pdje_python.audioPlayer_GetMusicControlPannel(self)

    def __init__(self, *args):
        _pdje_python.audioPlayer_swiginit(self, _pdje_python.new_audioPlayer(*args))
    __swig_destroy__ = _pdje_python.delete_audioPlayer

# Register audioPlayer in _pdje_python:
_pdje_python.audioPlayer_swigregister(audioPlayer)
class PDJE_Name_Sanitizer(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")

    def __init__(self, *args, **kwargs):
        raise AttributeError("No constructor defined")
    __repr__ = _swig_repr

    @staticmethod
    def sanitizeFileName(fileName):
        return _pdje_python.PDJE_Name_Sanitizer_sanitizeFileName(fileName)

    @staticmethod
    def getFileName(sanitized):
        return _pdje_python.PDJE_Name_Sanitizer_getFileName(sanitized)
    PDJE_SANITIZE_ERROR = property(_pdje_python.PDJE_Name_Sanitizer_PDJE_SANITIZE_ERROR_get, _pdje_python.PDJE_Name_Sanitizer_PDJE_SANITIZE_ERROR_set)

# Register PDJE_Name_Sanitizer in _pdje_python:
_pdje_python.PDJE_Name_Sanitizer_swigregister(PDJE_Name_Sanitizer)
cvar = _pdje_python.cvar

class MUS_VEC(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")
    __repr__ = _swig_repr

    def iterator(self):
        return _pdje_python.MUS_VEC_iterator(self)
    def __iter__(self):
        return self.iterator()

    def __nonzero__(self):
        return _pdje_python.MUS_VEC___nonzero__(self)

    def __bool__(self):
        return _pdje_python.MUS_VEC___bool__(self)

    def __len__(self):
        return _pdje_python.MUS_VEC___len__(self)

    def __getslice__(self, i, j):
        return _pdje_python.MUS_VEC___getslice__(self, i, j)

    def __setslice__(self, *args):
        return _pdje_python.MUS_VEC___setslice__(self, *args)

    def __delslice__(self, i, j):
        return _pdje_python.MUS_VEC___delslice__(self, i, j)

    def __delitem__(self, *args):
        return _pdje_python.MUS_VEC___delitem__(self, *args)

    def __getitem__(self, *args):
        return _pdje_python.MUS_VEC___getitem__(self, *args)

    def __setitem__(self, *args):
        return _pdje_python.MUS_VEC___setitem__(self, *args)

    def pop(self):
        return _pdje_python.MUS_VEC_pop(self)

    def append(self, x):
        return _pdje_python.MUS_VEC_append(self, x)

    def empty(self):
        return _pdje_python.MUS_VEC_empty(self)

    def size(self):
        return _pdje_python.MUS_VEC_size(self)

    def swap(self, v):
        return _pdje_python.MUS_VEC_swap(self, v)

    def begin(self):
        return _pdje_python.MUS_VEC_begin(self)

    def end(self):
        return _pdje_python.MUS_VEC_end(self)

    def rbegin(self):
        return _pdje_python.MUS_VEC_rbegin(self)

    def rend(self):
        return _pdje_python.MUS_VEC_rend(self)

    def clear(self):
        return _pdje_python.MUS_VEC_clear(self)

    def get_allocator(self):
        return _pdje_python.MUS_VEC_get_allocator(self)

    def pop_back(self):
        return _pdje_python.MUS_VEC_pop_back(self)

    def erase(self, *args):
        return _pdje_python.MUS_VEC_erase(self, *args)

    def __init__(self, *args):
        _pdje_python.MUS_VEC_swiginit(self, _pdje_python.new_MUS_VEC(*args))

    def push_back(self, x):
        return _pdje_python.MUS_VEC_push_back(self, x)

    def front(self):
        return _pdje_python.MUS_VEC_front(self)

    def back(self):
        return _pdje_python.MUS_VEC_back(self)

    def assign(self, n, x):
        return _pdje_python.MUS_VEC_assign(self, n, x)

    def resize(self, *args):
        return _pdje_python.MUS_VEC_resize(self, *args)

    def insert(self, *args):
        return _pdje_python.MUS_VEC_insert(self, *args)

    def reserve(self, n):
        return _pdje_python.MUS_VEC_reserve(self, n)

    def capacity(self):
        return _pdje_python.MUS_VEC_capacity(self)
    __swig_destroy__ = _pdje_python.delete_MUS_VEC

# Register MUS_VEC in _pdje_python:
_pdje_python.MUS_VEC_swigregister(MUS_VEC)
class TRACK_VEC(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")
    __repr__ = _swig_repr

    def iterator(self):
        return _pdje_python.TRACK_VEC_iterator(self)
    def __iter__(self):
        return self.iterator()

    def __nonzero__(self):
        return _pdje_python.TRACK_VEC___nonzero__(self)

    def __bool__(self):
        return _pdje_python.TRACK_VEC___bool__(self)

    def __len__(self):
        return _pdje_python.TRACK_VEC___len__(self)

    def __getslice__(self, i, j):
        return _pdje_python.TRACK_VEC___getslice__(self, i, j)

    def __setslice__(self, *args):
        return _pdje_python.TRACK_VEC___setslice__(self, *args)

    def __delslice__(self, i, j):
        return _pdje_python.TRACK_VEC___delslice__(self, i, j)

    def __delitem__(self, *args):
        return _pdje_python.TRACK_VEC___delitem__(self, *args)

    def __getitem__(self, *args):
        return _pdje_python.TRACK_VEC___getitem__(self, *args)

    def __setitem__(self, *args):
        return _pdje_python.TRACK_VEC___setitem__(self, *args)

    def pop(self):
        return _pdje_python.TRACK_VEC_pop(self)

    def append(self, x):
        return _pdje_python.TRACK_VEC_append(self, x)

    def empty(self):
        return _pdje_python.TRACK_VEC_empty(self)

    def size(self):
        return _pdje_python.TRACK_VEC_size(self)

    def swap(self, v):
        return _pdje_python.TRACK_VEC_swap(self, v)

    def begin(self):
        return _pdje_python.TRACK_VEC_begin(self)

    def end(self):
        return _pdje_python.TRACK_VEC_end(self)

    def rbegin(self):
        return _pdje_python.TRACK_VEC_rbegin(self)

    def rend(self):
        return _pdje_python.TRACK_VEC_rend(self)

    def clear(self):
        return _pdje_python.TRACK_VEC_clear(self)

    def get_allocator(self):
        return _pdje_python.TRACK_VEC_get_allocator(self)

    def pop_back(self):
        return _pdje_python.TRACK_VEC_pop_back(self)

    def erase(self, *args):
        return _pdje_python.TRACK_VEC_erase(self, *args)

    def __init__(self, *args):
        _pdje_python.TRACK_VEC_swiginit(self, _pdje_python.new_TRACK_VEC(*args))

    def push_back(self, x):
        return _pdje_python.TRACK_VEC_push_back(self, x)

    def front(self):
        return _pdje_python.TRACK_VEC_front(self)

    def back(self):
        return _pdje_python.TRACK_VEC_back(self)

    def assign(self, n, x):
        return _pdje_python.TRACK_VEC_assign(self, n, x)

    def resize(self, *args):
        return _pdje_python.TRACK_VEC_resize(self, *args)

    def insert(self, *args):
        return _pdje_python.TRACK_VEC_insert(self, *args)

    def reserve(self, n):
        return _pdje_python.TRACK_VEC_reserve(self, n)

    def capacity(self):
        return _pdje_python.TRACK_VEC_capacity(self)
    __swig_destroy__ = _pdje_python.delete_TRACK_VEC

# Register TRACK_VEC in _pdje_python:
_pdje_python.TRACK_VEC_swigregister(TRACK_VEC)
class KEY_VEC(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc="The membership flag")
    __repr__ = _swig_repr

    def iterator(self):
        return _pdje_python.KEY_VEC_iterator(self)
    def __iter__(self):
        return self.iterator()

    def __nonzero__(self):
        return _pdje_python.KEY_VEC___nonzero__(self)

    def __bool__(self):
        return _pdje_python.KEY_VEC___bool__(self)

    def __len__(self):
        return _pdje_python.KEY_VEC___len__(self)

    def __getslice__(self, i, j):
        return _pdje_python.KEY_VEC___getslice__(self, i, j)

    def __setslice__(self, *args):
        return _pdje_python.KEY_VEC___setslice__(self, *args)

    def __delslice__(self, i, j):
        return _pdje_python.KEY_VEC___delslice__(self, i, j)

    def __delitem__(self, *args):
        return _pdje_python.KEY_VEC___delitem__(self, *args)

    def __getitem__(self, *args):
        return _pdje_python.KEY_VEC___getitem__(self, *args)

    def __setitem__(self, *args):
        return _pdje_python.KEY_VEC___setitem__(self, *args)

    def pop(self):
        return _pdje_python.KEY_VEC_pop(self)

    def append(self, x):
        return _pdje_python.KEY_VEC_append(self, x)

    def empty(self):
        return _pdje_python.KEY_VEC_empty(self)

    def size(self):
        return _pdje_python.KEY_VEC_size(self)

    def swap(self, v):
        return _pdje_python.KEY_VEC_swap(self, v)

    def begin(self):
        return _pdje_python.KEY_VEC_begin(self)

    def end(self):
        return _pdje_python.KEY_VEC_end(self)

    def rbegin(self):
        return _pdje_python.KEY_VEC_rbegin(self)

    def rend(self):
        return _pdje_python.KEY_VEC_rend(self)

    def clear(self):
        return _pdje_python.KEY_VEC_clear(self)

    def get_allocator(self):
        return _pdje_python.KEY_VEC_get_allocator(self)

    def pop_back(self):
        return _pdje_python.KEY_VEC_pop_back(self)

    def erase(self, *args):
        return _pdje_python.KEY_VEC_erase(self, *args)

    def __init__(self, *args):
        _pdje_python.KEY_VEC_swiginit(self, _pdje_python.new_KEY_VEC(*args))

    def push_back(self, x):
        return _pdje_python.KEY_VEC_push_back(self, x)

    def front(self):
        return _pdje_python.KEY_VEC_front(self)

    def back(self):
        return _pdje_python.KEY_VEC_back(self)

    def assign(self, n, x):
        return _pdje_python.KEY_VEC_assign(self, n, x)

    def resize(self, *args):
        return _pdje_python.KEY_VEC_resize(self, *args)

    def insert(self, *args):
        return _pdje_python.KEY_VEC_insert(self, *args)

    def reserve(self, n):
        return _pdje_python.KEY_VEC_reserve(self, n)

    def capacity(self):
        return _pdje_python.KEY_VEC_capacity(self)
    __swig_destroy__ = _pdje_python.delete_KEY_VEC

# Register KEY_VEC in _pdje_python:
_pdje_python.KEY_VEC_swigregister(KEY_VEC)

