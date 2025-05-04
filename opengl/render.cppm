module;

export module opengl.render;

namespace opengl {

class ShaderCommon {
protected:
    int id_;

public:
    explicit ShaderCommon(int id)
      : id_{ id }
    {}
};

}
