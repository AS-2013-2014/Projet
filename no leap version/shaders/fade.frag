uniform sampler2D texture;
uniform sampler2D background;
uniform float a;
uniform float width;
uniform float height; 

void main(){
	vec2 tex = gl_FragCoord.xy;
	tex.x = tex.x/width;
	tex.y = 1.0-tex.y/height;
  vec4 p = texture2D(texture, gl_TexCoord[0].xy);
	vec4 pb = texture2D(background, tex);
	vec4 color;
	color.a = p.a;
	color.r = pb.r+(p.r-pb.r)*a;
	color.g = pb.g+(p.g-pb.g)*a;
	color.b = pb.b+(p.b-pb.b)*a;

  gl_FragColor = gl_Color*color;
}
