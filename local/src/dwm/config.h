/* See LICENSE file for copyright and license details. */
/* appearance */
static const unsigned int borderpx = 1; /* border pixel of windows */
static const unsigned int gappx = 5;
static const unsigned int snap = 32; /* snap pixel */
static const int swallowfloating = 0;
static const int smartgaps =
    0; /* 1 means no outer gap when there is only one window */
static const int showbar = 1; /* 0 means no bar */
static const int topbar = 1;  /* 0 means bottom bar */
static const int vertpad = 6;
static const int sidepad = 10;
static const int showsystray        = 1;     /* 0 means no systray */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;    /* 0: systray in the right corner, >0: systray on left of status text */
// static const unsigned int systrayspacing = 5;   /* systray spacing */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first */
static const char *fonts[]          = { "JetBrainsMono Nerd Font:size=12", "NotoColorEmoji:pixelsize=12:antialias=true:autohint=true", "monospace:size=13" };
static const char dmenufont[] = {"JetBrainsMono Nerd Font:size=12:antialias=true:autohint:true"};

static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#005577";
static char selbgcolor[]            = "#005577";
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

 // #include "/home/xtan/.cache/wal/colors-wal-dwm.h"

 /* tagging */
 // static const char *tags[] = {"1", "2", "3", "4", "5", "6", "7","8"};
 static const char *tags[] = { "", "2", "3", "4", "5", "6", "7"};

 static const Rule rules[] = {
     /* class      instance    title       tags mask     isfloating   monitor */
     {"Gimp", NULL, NULL, 0, 1, -1},
     {"Firefox", NULL, NULL, 1 << 8, 0, -1},
 };
 /* layout(s) */
static const float mfact = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    /* number of clients in master area */
static const int resizehints =
    1; /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen =
    1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[∀x]",  tile}, /* first entry is default */
    { "[¬l]",  NULL}, /* no layout function means floating behavior */
    { "[∃x]", monocle},
};

#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                      \
  {MODKEY, KEY, view, {.ui = 1 << TAG}},                                       \
      {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},               \
      {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},                        \
      {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
  }

void toggletiled(const Arg *arg) {
    if (selmon->sel) {
        if (selmon->sel->isfloating) {
            selmon->sel->isfloating = False;
            arrange(selmon);
        }
    }
}

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
// static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont};
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", selfgcolor, NULL };
static const char *termcmd[] = {"wezterm-gui", NULL};

/* commands */
static const char *headphoneconnect[] = {"headphoneconnect"};
static const char *alacritty[] = {"alacritty"};
static const char *sndcpyshimt[] = {"sndcpyshimt"};
static const char *delblur[] = {"delblur"};
static const char *addblur[] = {"addblur"};
static const char *scrcpyshit[] = {"scrcpyshit"};
static const char *flameshotgui[] = {"flameshotgui"};
static const char *w3mterm[] = {"w3mterm"};
// static const char *dmenucmd[] = {"dmenu_run", "-m", dmenumon, "-fn",
// dmenufont}; static const char *termcmd[] = {"alacritty", NULL};
static const char *roficmd[] = {
    "rofi", "-show", "drun", "-icon-theme", " Papirus", "-show-icons", NULL};
static const char *files[] = {"thunar", NULL};
static const char *emacs[] = {"emacsclient", "-c", NULL};
static const char *pavucontrol[] = {"pavucontrol", NULL};

static Key keys[] = {
    /* modifier                     key        function        argument */
    // Applications
    {MODKEY, XK_9, spawn, {.v = headphoneconnect}},
    {MODKEY, XK_a, spawn, {.v = alacritty}},
    {MODKEY, XK_7, spawn, {.v = sndcpyshimt}},
    {MODKEY, XK_i, spawn, {.v = delblur}},
    {MODKEY, XK_u, spawn, {.v = addblur}},
    {MODKEY, XK_y, spawn, {.v = scrcpyshit}},
    {MODKEY, XK_n, spawn, {.v = w3mterm}},
    {MODKEY, XK_m, spawn, {.v = flameshotgui}},
    {MODKEY, XK_r, spawn, {.v = roficmd}},
    {MODKEY, XK_a, spawn, {.v = emacs}},
    {MODKEY, XK_v, spawn, {.v = pavucontrol}},
    {MODKEY, XK_e, spawn, {.v = files}},
    {MODKEY, XK_d, spawn, {.v = dmenucmd}},
    {MODKEY, XK_Return, spawn, {.v = termcmd}},
   	{ MODKEY,                       XK_F5,     xrdb,           {.v = NULL } },
    // { MODKEY,                       XK_p,      spawn,          {.v = powercmd
    // } },
    //  {MODKEY | ShiftMask, XK_f, spawn, {.v = browser}},

    {MODKEY, XK_b, togglebar, {0}},

    // stack commands
    {MODKEY, XK_j, focusstack, {.i = +1}},
    {MODKEY, XK_k, focusstack, {.i = -1}},

    // master commands
    {MODKEY, XK_bracketleft, incnmaster, {.i = +1}},
    {MODKEY, XK_bracketright, incnmaster, {.i = -1}},

    // resize
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    /* { MODKEY,                       XK_Return, zoom,           {0} }, */
    {MODKEY, XK_Tab, view, {0}},
    {MODKEY, XK_q, killclient, {0}},
    // layouts set
    {MODKEY, XK_t, setlayout, {.v = &layouts[0]}}, // tiling
    {MODKEY, XK_f, setlayout, {.v = &layouts[1]}}, // floating
    {MODKEY, XK_p, setlayout, {.v = &layouts[2]}}, // monocle

    // { MODKEY|ShiftMask,             XK_m,      reset,    {0} },
    // layouts
    {MODKEY, XK_space, setlayout, {0}},
    {MODKEY | ShiftMask, XK_space, togglefloating, {0}},
    {MODKEY | ShiftMask, XK_l, toggletiled, {0}},
    //  { MODKEY|ShiftMask, XK_i, spawn, {.v = sscmd } },
    {MODKEY, XK_0, view, {.ui = ~0}},
    {MODKEY | ShiftMask, XK_0, tag, {.ui = ~0}},
    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_comma, tagmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_period, tagmon, {.i = +1}},

    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)
        TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5){MODKEY | ShiftMask, XK_q, quit, {0}},
};

/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function argument */
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};

