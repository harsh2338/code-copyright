// const JaccardsSimilarity = artifacts.require("JaccardsSimilarity");
// Array.prototype.equals = function (arr2) {
//   return (
//     this.length === arr2.length &&
//     this.every((value, index) => value === arr2[index])
//   );
// };
// contract("Test Jaccards Score", async () => {
//   it("should provide the right jaccarsd score", async () => {
//     const contract = await JaccardsSimilarity.deployed();

//     const hashSet1 = [
//       "47c4c1ab373a840d666dc61d9af1ff29",
//       "e75cc2ca4058524c13fd6a1473325d00",
//       "72801233251db633f619c753aa70d2f9",
//       "87781147fa92daa2215037c8889087fe",
//       "d4f1f58a5d87245566e409c243f2e2bf",
//       "e2f7ea073f65fce7b124bf72dbb061ad",
//       "f0ac921fc7013af6fafc53bf48c3c794",
//       "2abae8e7927ce57a18b9477be91c5ed9",
//       "08379bf03ad0003676e78313c60fb848",
//       "afdee93594bcdad7ba401a0072193e0a",
//       "018dd1e07a2de4a08e6612341bf2323e",
//       "3f27e3cafa4ed5fcea61f7c24977a154",
//       "89befd1102aeaead24cfe2b9fa9997f9",
//     ];

//         const hashSet2 = [
//           "47c4c1ab373a840d666dc61d9af1ff29",
//           "e75cc2ca4058524c13fd6a1473325d00",
//           "72801233251db633f619c753aa70d2f9",
//           "87781147fa92daa2215037c8889087fe",
//           "d4f1f58a5d87245566e409c243f2e2bf",
//           "e2f7ea073f65fce7b124bf72dbb061ad",
//           "f0ac921fc7013af6fafc53bf48c3c794",
//           "2abae8e7927ce57a18b9477be91c5ed9",
//           "08379bf03ad0003676e78313c60fb848",
//           "afdee93594bcdad7ba401a0072193e0a",
//           "018dd1e07a2de4a08e6612341bf2323e",
//           "3f27e3cafa4ed5fcea61f7c24977a154",
//           "89befd1102aeaead24cfe2b9fa9997f9",
//         ];


//     contract.

//     const res1 = await contract.getFiles(1);
//     assert.equal(res1.fileIPFSHash, docCID);
//     assert.equal(res1.codeFingerPrint, codeFingerPrint);

//     // assert.equal(res1.hashSet, hashSet);
//     // console.log(res1.hashSet.equals(hashSet));
//     // console.log(res1);
//   });
// });
