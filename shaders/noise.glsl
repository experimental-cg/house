
float n(vec2 co){
    return fract(sin(dot(co, vec2(12.9898, 78.233))) * 43758.5453);
}

float sn(vec2 s) {
    vec2 fs  = floor(s);
    vec2 ds  = s - fs;
    vec2 dsi = 1 - ds;
    float a0, a1;

    a0 = n(fs + vec2(0,0)) * dsi.x + n(fs + vec2(1,0)) * ds.x;
    a1 = n(fs + vec2(0,1)) * dsi.x + n(fs + vec2(1,1)) * ds.x;

    return a0 * dsi.y + a1 * ds.y;
}

float ws(int depth, float a, float b, float x) {
    float y = 0.0;

    for (int k = 1; k < depth; k++) {
        y += sin(3.14 * pow(k, a) * pow(k, b) * x) / pow(k, a);
    }
    return y;
}

float rand(vec2 co) {
    return fract(sin(dot(co, vec2(12.9898, 78.233))) * 43758.5453);
}

int sn_iter = 1;
float sn(vec2 s) {
    float a0 = rand(sn_iter*(floor(s) + vec2(0,0)))*(1 - (s.x-floor(s.x))) + rand(sn_iter*(floor(s) + vec2(1,0)))*(s.x-floor(s.x));
    float a1 = rand(sn_iter*(floor(s) + vec2(0,1)))*(1 - (s.x-floor(s.x))) + rand(sn_iter*(floor(s) + vec2(1,1)))*(s.x-floor(s.x));
    sn_iter++;
    return a0*(1 - (s.y-floor(s.y))) + a1*(s.y - floor(s.y));
}

float sn2(vec2 s, int count) {
    float result = 0.0;
    for (int i = 0; i < count; i++) {
        result += sn(s);
    }
    return result/count;
}
