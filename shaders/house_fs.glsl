#version 330 core

uniform sampler2D tex;

out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;
in vec3 LightPos;
in vec3 color;

in vec2 TexCoords;

void main()
{
    // vec3 ambient = light.ambient * material.ambient;

    // // diffuse lighting
    // vec3 norm = normalize(Normal);
    // vec3 lightDir = normalize(LightPos - FragPos);

    // float diff = max(dot(norm, lightDir), 0.0);
    // vec3 diffuse = light.diffuse * (diff * material.diffuse);

    // // specular lighting
    // vec3 viewDir = normalize(-FragPos);
    // vec3 reflectDir = reflect(-lightDir, norm);
    // float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // vec3 specular = light.specular * (spec * material.specular);

    // vec3 result = ambient + diffuse + specular;
    //FragColor = vec4(vec3(0.8,0.4,0.3), 1.0);

    FragColor = texture(tex, TexCoords);

    //FragColor = vec4(color, 1.0);
    //FragColor = vec4(vec3(cos(dot(viewDir, reflectDir)*20)), 1.0);
    //FragColor = vec4(vec3(0.5*exp(dot(viewDir, reflectDir)*4)), 1.0);
}
