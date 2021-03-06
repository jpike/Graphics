#include "Graphics/OpenGL/OpenGL.h"

namespace GRAPHICS
{
namespace OPEN_GL
{
    PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB = nullptr;
    PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = nullptr;
    PFNGLGENBUFFERSPROC glGenBuffers = nullptr;
    PFNGLBINDBUFFERPROC glBindBuffer = nullptr;
    PFNGLBUFFERDATAPROC glBufferData = nullptr;
    PFNGLCREATESHADERPROC glCreateShader = nullptr;
    PFNGLSHADERSOURCEPROC glShaderSource = nullptr;
    PFNGLCOMPILESHADERPROC glCompileShader = nullptr;
    PFNGLGETSHADERIVPROC glGetShaderiv = nullptr;
    PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog = nullptr;
    PFNGLCREATEPROGRAMPROC glCreateProgram = nullptr;
    PFNGLATTACHSHADERPROC glAttachShader = nullptr;
    PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation = nullptr;
    PFNGLLINKPROGRAMPROC glLinkProgram = nullptr;
    PFNGLUSEPROGRAMPROC glUseProgram = nullptr;
    PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation = nullptr;
    PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer = nullptr;
    PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray = nullptr;
    PFNGLGENVERTEXARRAYSPROC glGenVertexArrays = nullptr;
    PFNGLBINDVERTEXARRAYPROC glBindVertexArray = nullptr;
    PFNGLDELETEPROGRAMPROC glDeleteProgram = nullptr;
    PFNGLDELETESHADERPROC glDeleteShader = nullptr;
    PFNGLDELETEBUFFERSPROC glDeleteBuffers = nullptr;
    PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays = nullptr;
    PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation = nullptr;
    PFNGLUNIFORM3FPROC glUniform3f = nullptr;
    PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv = nullptr;

    /// Attempts to load all necessary OpenGL functions.
    /// @return True if loading succeeds; false otherwise.
    bool LoadOpenGLFunctions()
    {
        // LOAD OPEN GL FUNCTIONS.
        wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC)wglGetProcAddress("wglChoosePixelFormatARB");
        wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");
        glGenBuffers = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
        glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
        glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
        glCreateShader = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
        glShaderSource = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
        glCompileShader = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
        glGetShaderiv = (PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");
        glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
        glCreateProgram = (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
        glAttachShader = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
        glBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONPROC)wglGetProcAddress("glBindFragDataLocation");
        glLinkProgram = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
        glUseProgram = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
        glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)wglGetProcAddress("glGetAttribLocation");
        glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");
        glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glEnableVertexAttribArray");
        glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)wglGetProcAddress("glGenVertexArrays");
        glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)wglGetProcAddress("glBindVertexArray");
        glDeleteProgram = (PFNGLDELETEPROGRAMPROC)wglGetProcAddress("glDeleteProgram");
        glDeleteShader = (PFNGLDELETESHADERPROC)wglGetProcAddress("glDeleteShader");
        glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)wglGetProcAddress("glDeleteBuffers");
        glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)wglGetProcAddress("glDeleteVertexArrays");
        glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");
        glUniform3f = (PFNGLUNIFORM3FPROC)wglGetProcAddress("glUniform3f");
        glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)wglGetProcAddress("glUniformMatrix4fv");

        // CHECK IF LOADING SUCCEEDED.
        bool loading_succeeded = (
            wglChoosePixelFormatARB &&
            wglCreateContextAttribsARB &&
            glGenBuffers &&
            glBindBuffer &&
            glBufferData &&
            glCreateShader &&
            glShaderSource &&
            glCompileShader &&
            glGetShaderiv &&
            glGetShaderInfoLog &&
            glCreateProgram &&
            glAttachShader &&
            glBindFragDataLocation &&
            glLinkProgram &&
            glUseProgram &&
            glGetAttribLocation &&
            glVertexAttribPointer &&
            glEnableVertexAttribArray &&
            glGenVertexArrays &&
            glBindVertexArray &&
            glDeleteProgram &&
            glDeleteShader &&
            glDeleteBuffers &&
            glDeleteVertexArrays &&
            glGetUniformLocation &&
            glUniform3f &&
            glUniformMatrix4fv);
        return loading_succeeded;
    }

    /// Initializes OpenGL by loading the necessary functions.
    /// @param[in] device_context - The device context for which OpenGL should be initialized.
    /// @return True if initialization succeeds; false otherwise.
    bool Initialize(const HDC device_context)
    {
        // SET THE PIXEL FORMAT.
        PIXELFORMATDESCRIPTOR pixel_format = {};
        pixel_format.nSize = sizeof(pixel_format);
        const WORD REQUIRED_VERSION = 1;
        pixel_format.nVersion = REQUIRED_VERSION;
        pixel_format.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
        pixel_format.iPixelType = PFD_TYPE_RGBA;
        pixel_format.cColorBits = 32;
        pixel_format.cDepthBits = 24;
        pixel_format.cStencilBits = 8;

        const int FAILED_TO_FIND_PIXEL_FORMAT = 0;
        int temp_pixel_format_index = ChoosePixelFormat(device_context, &pixel_format);
        bool pixel_format_chosen = (FAILED_TO_FIND_PIXEL_FORMAT != temp_pixel_format_index);
        if (!pixel_format_chosen)
        {
            return false;
        }

        BOOL pixel_format_set = SetPixelFormat(device_context, temp_pixel_format_index, &pixel_format);
        if (!pixel_format_set)
        {
            return false;
        }

        // CREATE A TEMPORARY OPEN GL RENDERING CONTEXT.
        // This is necessary in order to load the OpenGL functions.
        HGLRC temp_open_gl_render_context = wglCreateContext(device_context);
        bool temp_open_gl_render_context_created = (NULL != temp_open_gl_render_context);
        if (!temp_open_gl_render_context_created)
        {
            return nullptr;
        }

        BOOL open_gl_context_made_current = wglMakeCurrent(device_context, temp_open_gl_render_context);
        if (!open_gl_context_made_current)
        {
            return nullptr;
        }

        // LOAD THE OPEN GL FUNCTIONS.
        bool open_gl_functions_loaded = LoadOpenGLFunctions();
        if (!open_gl_functions_loaded)
        {
            return nullptr;
        }

        // SET THE PIXEL FORMAT.
        const int pixel_format_attribute_list[] =
        {
            WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
            WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
            WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
            WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
            WGL_COLOR_BITS_ARB, 32,
            WGL_DEPTH_BITS_ARB, 24,
            WGL_STENCIL_BITS_ARB, 8,
            ATTRIBUTE_LIST_TERMINATOR
        };
        const float* const NO_FLOATING_POINT_PIXEL_FORMAT_ATTRIBUTES = nullptr;
        const unsigned int MAX_PIXEL_FORMATS_TO_CHOOSE = 1;
        int pixel_format_index = 0;
        UINT pixel_format_count = 0;

        BOOL gl_pixel_format_chosen = wglChoosePixelFormatARB(
            device_context,
            pixel_format_attribute_list,
            NO_FLOATING_POINT_PIXEL_FORMAT_ATTRIBUTES,
            MAX_PIXEL_FORMATS_TO_CHOOSE,
            &pixel_format_index,
            &pixel_format_count);
        if (!gl_pixel_format_chosen)
        {
            return nullptr;
        }
        SetPixelFormat(device_context, pixel_format_index, &pixel_format);

        // DELETE THE TEMPORARY OPEN GL RENDERING CONTEXT.
        wglDeleteContext(temp_open_gl_render_context);

        return true;
    }
}
}
