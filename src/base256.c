#include <string.h>
#include <stdbool.h>

#include <base256.h>
#include "uthash.h"

static const char* enc_tab[2][256] = {{
    "😀", "😁", "😂", "😃", "😄", "😅", "😆", "😉", "😊", "😋", "😎", "😍", "😘", "😗", "😙", "😚",
    "🙂", "🤗", "🤔", "😐", "😑", "😶", "🙄", "😏", "😣", "😥", "😮", "🤐", "😯", "😪", "😫", "😴",
    "😌", "🤓", "😛", "😜", "😝", "😒", "😓", "😔", "😕", "🙃", "🤑", "😲", "🙁", "😖", "😞", "😟",
    "😤", "😢", "😭", "😦", "😨", "😩", "😬", "😰", "😱", "😳", "😵", "😡", "😠", "😇", "😷", "🤒",
    "🤕", "😈", "👿", "👹", "👺", "💀", "👻", "👽", "👾", "🤖", "💩", "😺", "😸", "😹", "😻", "😼",
    "😽", "🙀", "😿", "😾", "🙈", "🙉", "🙊", "👦", "👧", "👨", "👩", "👴", "👵", "👶", "👼", "👮",
    "🕵", "💂", "👷", "👳", "👱", "🎅", "👸", "👰", "👲", "🙍", "🙎", "🙅", "🙆", "💁", "🙋", "🙇",
    "💆", "💇", "🚶", "🏃", "💃", "👯", "🕴", "🗣", "👤", "👥", "🏇", "🏂", "🏌", "🏄", "🚣", "🏊",
    "🏋", "🚴", "🚵", "🏎", "🏍", "👫", "👬", "👭", "💏", "💑", "👪", "💪", "👈", "👉", "👆", "🖕",
    "👇", "🖖", "🤘", "🖐", "👌", "👍", "👎", "👊", "👋", "👏", "👐", "🙌", "🙏", "💅", "👂", "👃",
    "👣", "👀", "👁", "👅", "👄", "💋", "💘", "💓", "💔", "💕", "💖", "💗", "💙", "💚", "💛", "💜",
    "💝", "💞", "💟", "💌", "💤", "💢", "💣", "💥", "💦", "💨", "💫", "💬", "🗨", "🗯", "💭", "🕳",
    "👓", "🕶", "👔", "👕", "👖", "👗", "👘", "👙", "👚", "👛", "👜", "👝", "🛍", "🎒", "👞", "👟",
    "👠", "👡", "👢", "👑", "👒", "🎩", "🎓", "📿", "💄", "💍", "💎", "🐵", "🐒", "🐶", "🐕", "🐩",
    "🐺", "🐱", "🐈", "🦁", "🐯", "🐅", "🐆", "🐴", "🐎", "🦄", "🐮", "🐂", "🐃", "🐄", "🐷", "🐖",
    "🐗", "🐽", "🐏", "🐑", "🐐", "🐪", "🐫", "🐘", "🐭", "🐁", "🐀", "🐹", "🐰", "🐇", "🐿", "🐻"
}, {
    "🐨", "🐼", "🐾", "🦃", "🐔", "🐓", "🐣", "🐤", "🐥", "🐦", "🐧", "🕊", "🐸", "🐊", "🐢", "🐍",
    "🐲", "🐉", "🐳", "🐋", "🐬", "🐟", "🐠", "🐡", "🐙", "🐚", "🦀", "🐌", "🐛", "🐜", "🐝", "🐞",
    "🕷", "🕸", "🦂", "💐", "🌸", "💮", "🏵", "🌹", "🌺", "🌻", "🌼", "🌷", "🌱", "🌲", "🌳", "🌴",
    "🌵", "🌾", "🌿", "🍀", "🍁", "🍂", "🍃", "🍇", "🍈", "🍉", "🍊", "🍋", "🍌", "🍍", "🍎", "🍏",
    "🍐", "🍑", "🍒", "🍓", "🍅", "🍆", "🌽", "🌶", "🍄", "🌰", "🍞", "🧀", "🍖", "🍗", "🍔", "🍟",
    "🍕", "🌭", "🌮", "🌯", "🍳", "🍲", "🍿", "🍱", "🍘", "🍙", "🍚", "🍛", "🍜", "🍝", "🍠", "🍢",
    "🍣", "🍤", "🍥", "🍡", "🍦", "🍧", "🍨", "🍩", "🍪", "🎂", "🍰", "🍫", "🍬", "🍭", "🍮", "🍯",
    "🍼", "🍵", "🍶", "🍾", "🍷", "🍸", "🍹", "🍺", "🍻", "🍽", "🍴", "🔪", "🏺", "🌍", "🌎", "🌏",
    "🌐", "🗺", "🗾", "🏔", "🌋", "🗻", "🏕", "🏖", "🏜", "🏝", "🏞", "🏟", "🏛", "🏗", "🏘", "🏙",
    "🏚", "🏠", "🏡", "🏢", "🏣", "🏤", "🏥", "🏦", "🏨", "🏩", "🏪", "🏫", "🏬", "🏭", "🏯", "🏰",
    "💒", "🗼", "🗽", "🕌", "🕍", "🕋", "🌁", "🌃", "🌄", "🌅", "🌆", "🌇", "🌉", "🌌", "🎠", "🎡",
    "🎢", "💈", "🎪", "🎭", "🖼", "🎨", "🎰", "🚂", "🚃", "🚄", "🚅", "🚆", "🚇", "🚈", "🚉", "🚊",
    "🚝", "🚞", "🚋", "🚌", "🚍", "🚎", "🚐", "🚑", "🚒", "🚓", "🚔", "🚕", "🚖", "🚗", "🚘", "🚙",
    "🚚", "🚛", "🚜", "🚲", "🚏", "🛣", "🛤", "🚨", "🚥", "🚦", "🚧", "🚤", "🛳", "🛥", "🚢", "🛩",
    "🛫", "🛬", "💺", "🚁", "🚟", "🚠", "🚡", "🚀", "🛰", "🛎", "🚪", "🛌", "🛏", "🛋", "🚽", "🚿",
    "🛀", "🛁", "🕰", "🌞", "🌝", "🌚", "🌑", "🌒", "🌓", "🌔", "🌕", "🌖", "🌗", "🌘", "🌜", "🌛"
}};

typedef struct base256_entity {
    const char* index;
    char val;
    UT_hash_handle hh;
} base256_entity;

static base256_entity* dec_tab = NULL;

static bool has_dec_initialized = false;

void base256_init_dec(void)
{
    for (int i = 0; i < 512; i++) {
        base256_entity* e = (base256_entity*)malloc(sizeof(base256_entity));
        e->index = enc_tab[i / 256][i % 256];
        e->val = i;
        HASH_ADD_KEYPTR(hh, dec_tab, e->index, 4, e);
    }

    has_dec_initialized = true;
}

// in fact, it should never returns an error?
int base256_encode(char* out, int out_size,
                   const unsigned char* in, int in_size)
{
    register unsigned char table = 0;
    int i = 0;
    int o = 0;

    while (i < in_size && o < out_size - 1) {
        memcpy(out + o, enc_tab[table][in[i]], 4);

        table = 1 - table;
        i++;
        o += 4;
    }
    out[o] = '\x00';

    return o + 1;
}

int base256_decode(unsigned char* out, int out_size,
                   const char* in)
{
    if (!has_dec_initialized) {
        return BASE256_ERR_NO_DEC_INIT;
    }

    int in_size = strlen(in);
    int i = 0;
    int o = 0;

    const char* cur;
    base256_entity* e = NULL;

    do {
        cur = in + i;

        HASH_FIND(hh, dec_tab, cur, 4, e);
        if (e == NULL) {
            return BASE256_ERR_BAD_INPUT;
        }

        out[o] = e->val;

        i += 4;
        o++;
    } while (i < in_size && o < out_size);

    return o;
}
