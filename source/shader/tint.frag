uniform sampler2D texture;

uniform vec4 flashColor;

void main() {

    vec4 pixel_color = texture2D(texture, gl_TexCoord[0].xy);
    float percent = 1;

    vec4 colorDifference = vec4(0, 0, 0, 1);

    colorDifference.r = flashColor.r - pixel_color.r;
    colorDifference.g = flashColor.g - pixel_color.g;
    colorDifference.b = flashColor.b - pixel_color.b;
    pixel_color.r = pixel_color.r + colorDifference.r * percent;
    pixel_color.g = pixel_color.g + colorDifference.g * percent;
    pixel_color.b = pixel_color.b + colorDifference.b * percent;

    gl_FragColor = pixel_color; 
}

/*
sf::Shader shader;
shader.loadFromFile("shader/tint.frag", sf::Shader::Fragment);
shader.setUniform("flashColor", sf::Glsl::Vec4(1, 1, 1, 1));
*/
