// SPDX-License-Identifier: MIT
pragma solidity >=0.4.22 <0.9.0;




contract PlagiarismContract 
{
/**
languages
0: CPP
1: Java
2: JavaScript
 */

  struct CodeFile{
    uint fileId;
    uint fileSize;
    string fileIPFSCID;
    string fileName;
    string fileDescription;
    address codeAuthor;
    uint timeUploaded;    
    string codeFingerPrint;
    bytes16 [] hashSet;
    uint hashSetLength;
    uint language;
  }
  uint[] public fileCountByLanguage = [0,0,0];
  uint public totalFileCount=0;


  //TODO: Use actual threshold
  uint[] public threshold=[30,30,30];


  mapping(uint=>mapping(uint=>CodeFile)) public filesMapByLanguage;

  mapping(address=>mapping(uint=>uint[])) public userFilesIndexByLanguage;

  mapping(string=>bool)IPFSCIDsMap;


  event CodeFileUploadEvent(
    uint fileId,
    uint fileSize,
    string fileIPFSCID,
    string fileName,
    string fileDescription,
    address codeAuthor,
    uint timeUploaded ,
    string codeFingerPrint,
    bytes16 [] hashSet,
    uint hashSetLength,
    uint language
  ) ;

  event GetFilesEvent(
    CodeFile[] codefiles
  );

  event PlagiarismResult(
    bool plagiarisedResult
  );


//getUploaded files
// different maps for different langiages
// map to check if same file
//reject if any file has higher similarity score than threshold


  function getFilesUploadedByUser()public view returns (CodeFile[] memory){
    uint cppFileCount=userFilesIndexByLanguage[msg.sender][0].length;
    uint javaFileCount=userFilesIndexByLanguage[msg.sender][1].length;
    uint javaScriptFileCount=userFilesIndexByLanguage[msg.sender][2].length;

    CodeFile[] memory listOfFiles = new CodeFile[](cppFileCount+javaFileCount+javaScriptFileCount);   

    uint currentCount=0;
    for(uint i=0;i<cppFileCount;i++){
      listOfFiles[currentCount]=getFileByIndex(userFilesIndexByLanguage[msg.sender][0][i],0);
      currentCount++;
    }    
    for(uint i=0;i<javaFileCount;i++){
      listOfFiles[currentCount]=getFileByIndex(userFilesIndexByLanguage[msg.sender][1][i],1);
      currentCount++;
    }
    for(uint i=0;i<javaScriptFileCount;i++){
      listOfFiles[currentCount]=getFileByIndex(userFilesIndexByLanguage[msg.sender][2][i],2);
      currentCount++;
    }
    return listOfFiles;

  }
  function uploadFile(uint _fileSize, string memory  _fileIPFSCID, string memory  _fileName,string memory  _fileDescription, string memory  _codeFingerPrint, bytes16 [] memory _hashSet, uint hashSetLength, uint language) public {

    // Returns if same file is uploaded
    if(IPFSCIDsMap[_fileIPFSCID]==true){
      emit PlagiarismResult(true);
    }
    else if(checkIfPlagiarised(_hashSet,hashSetLength,language)){
      emit PlagiarismResult(true);
    }
    else{
      fileCountByLanguage[language]++;
      totalFileCount++;
      IPFSCIDsMap[_fileIPFSCID]==true;
      filesMapByLanguage[language][fileCountByLanguage[language]] = CodeFile(totalFileCount,_fileSize,_fileIPFSCID, _fileName, _fileDescription,msg.sender,block.timestamp,_codeFingerPrint,_hashSet,hashSetLength,language);
      userFilesIndexByLanguage[msg.sender][language].push(fileCountByLanguage[language]);
      emit CodeFileUploadEvent(totalFileCount,_fileSize,_fileIPFSCID, _fileName, _fileDescription,msg.sender,block.timestamp,_codeFingerPrint,_hashSet,hashSetLength,language);
    }
  }

    function getFileByIndex(uint _fileIndex,uint language)
        public
        view
        returns (CodeFile memory records)
    {
        return filesMapByLanguage[language][_fileIndex];
    }

    function getFileHashSet(uint _fileIndex, uint language) private
        view
        returns (bytes16 [] memory )
    {
        return filesMapByLanguage[language][_fileIndex].hashSet;
    }

    function getFileHashSetLength(uint _fileIndex,uint language) private
        view
        returns (uint )
    {
        return filesMapByLanguage[language][_fileIndex].hashSetLength;
    }
    function checkIfPlagiarised( bytes16 [] memory _hashSet, uint hashSetLength,uint language)public view returns(bool){

      uint similarity=0;

      for(uint i=1;i<=fileCountByLanguage[language];i++){
        bytes16 [] memory existingFilehashSet=getFileHashSet(i,language);
        uint existingFilehashSetLength=getFileHashSetLength(i,language);
        similarity=calculateSimilarityScore(_hashSet,existingFilehashSet,hashSetLength,existingFilehashSetLength);
        if(similarity>threshold[language]){
          return true;
        }
      }
      
      return false;
    }

    // function getMaximumSimilarityScore( bytes16 [] memory _hashSet, uint oriHashSetLength,uint language) public view returns (uint){
    //   uint similarity=0;

    //   for(uint i=1;i<=fileCountByLanguage[language];i++){
    //     bytes16 [] memory existingFilehashSet=getFileHashSet(i,language);
    //     uint existingFilehashSetLength=getFileHashSetLength(i,language);
    //     similarity=calculateSimilarityScore(_hashSet,existingFilehashSet,oriHashSetLength,existingFilehashSetLength);
    //     if(similarity>threshold){
    //       break;
    //     }
    //   }
    //   return similarity;
    // }

 
    
    function getCommonElementsCount(bytes16[] memory list1, bytes16[] memory list2,uint setLength1,uint setLength2) public pure returns (uint){

        uint commonElementsCount=0;
        for(uint i=0;i< setLength1;i++){
            for(uint j=0;j<setLength2;j++){
                if(list1[i]==list2[j]){
                    commonElementsCount++;
                    break;
                }
            }
        }
        return commonElementsCount;
    }

    function calculateSimilarityScore(bytes16[] memory l1, bytes16[] memory l2, uint l1OriLength, uint l2OriLength) public pure returns(uint){

      uint commonElementsCount = getCommonElementsCount(l1,l2,l1.length,l2.length);
      uint unionCount=l1OriLength+l2OriLength-commonElementsCount;        
      
      return commonElementsCount*100/unionCount;
    } 
}