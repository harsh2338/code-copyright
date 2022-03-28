import { printTree, printTreeFromFilePath } from "./index.js";
import Jaccard from "jaccard-index";

import fs from "fs";
var files = fs.readdirSync("./data/cpp");


var jaccard = Jaccard();

var hs1, hs2;
var jaccAns = [];



var start = new Date().getTime();

for(let i=0;i<100;i++){
    hs1 = printTreeFromFilePath(2, `./data/cpp/${i}.cpp`);
}
var end = new Date().getTime();
var time = end - start;
console.log(time)
// hs2 = printTree(2, `./data/cpp/${files[0]}`);
// jaccAns.push(jaccard.index(hs1, hs2));
// console.log(jaccAns);
