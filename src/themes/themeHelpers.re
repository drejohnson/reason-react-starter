/* adapted from https://github.com/SentiaAnalytics/bs-css/blob/master/src/Css.re  */
open Types;

/* colors */
let rgb: rgb = (r, g, b) => {j|rgb($r, $g, $b)|j};

let rgba: rgba = (r, g, b, a) => {j|rgba($r, $g, $b, $a)|j};

let hex: hex = (v) => {j|#$(v)|j};

/* units */
let px: px = (i) => {j|$(i)px|j};

let pct: pct = (i) => {j|$(i)%|j};

let rem: rem = (i) => {j|$(i)rem|j};

let em: em = (i) => {j|$(i)em|j};

let cm: cm = (i) => {j|$(i)cm|j};

let mm: mm = (i) => {j|$(i)mm|j};

let vh: vh = (i) => {j|$(i)vh|j};

let vw: vw = (i) => {j|$(i)vw|j};

let zero: zero = "0";