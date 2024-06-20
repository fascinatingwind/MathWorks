#version 450

layout(location = 0) in vec3 fragColor;
layout(location = 1) in vec2 fragTexColor;

layout(location = 0) out vec4 outColor;
layout(binding = 1) uniform sampler2D texSampler;

void main() {
    //outColor = texture(texSampler, fragTexColor * 2.0);
    outColor = vec4(fragColor * texture(texSampler, fragTexColor).rgb, 1.0);
}