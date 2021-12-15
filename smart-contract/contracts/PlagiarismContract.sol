// SPDX-License-Identifier: MIT
pragma solidity >=0.4.22 <0.9.0;
pragma experimental ABIEncoderV2;
contract PlagiarismContract {

  struct CodeFile{
    uint fileId;
    uint fileSize;
    string fileIPFSHash;
    string fileName;
    string fileDescription;
    address codeAuthor;
    uint timeUploaded;    
    string codeFingerPrint;
    string [] hashSet;
  }

  uint public fileCount = 0;
  mapping(uint=>CodeFile) public filesMap;


  event CodeFileUploadEvent(
    uint fileId,
    uint fileSize,
    string fileIPFSHash,
    string fileName,
    string fileDescription,
    address codeAuthor,
    uint timeUploaded ,
    string codeFingerPrint,
    string [] hashSet
  ) ;

  constructor() public {
  }

  function uploadFile(uint _fileSize, string memory _fileIPFSHash, string memory _fileName,string memory _fileDescription, string memory _codeFingerPrint, string [] memory _hashSet) public {
    require(bytes(_fileIPFSHash).length > 0, "CodeFile Hash is empty");

    require(bytes(_fileDescription).length > 0, "CodeFile description is empty");

    require(bytes(_fileName).length > 0, "CodeFile name is empty");

    require(_fileSize>0, "CodeFile size is 0");

    fileCount++;

    filesMap[fileCount] = CodeFile(fileCount,_fileSize,_fileIPFSHash, _fileName, _fileDescription,msg.sender,block.timestamp,_codeFingerPrint,_hashSet);

    emit CodeFileUploadEvent(fileCount,_fileSize,_fileIPFSHash, _fileName, _fileDescription,msg.sender,block.timestamp,_codeFingerPrint,_hashSet);
  }

    function getFiles(uint _fileIndex)
        public
        view
        returns (CodeFile memory records)
    {
        return filesMap[_fileIndex];
    }

}