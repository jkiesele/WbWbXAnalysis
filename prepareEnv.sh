#!/bin/zsh

mkdir -p ${CMSSW_BASE}/external/${SCRAM_ARCH}/lib
cd ${CMSSW_BASE}/src/TtZAnalysis

if [[ -a ${CMSSW_BASE}/external/${SCRAM_ARCH}/lib/libunfold.so && -a ../TopAnalysis/ZTopUtils/BuildFile.xml &&  -a ../FWCore/FWLite/BuildFile.xml ]]
then
    echo "CMSSW release already prepared for TtZAnalysis Framework"
else
    if [[ ! -a ../TopAnalysis/ZTopUtils/BuildFile.xml ]]
    then
	echo "TtZAnalysis depends on the TopAnalysis/ZTopUtils package. Please check it out by hand"
	exit 1
    elif  [[ ! -a ${CMSSW_BASE}/external/${SCRAM_ARCH}/lib/libunfold.so ]]
    then
	ln -s ${CMSSW_BASE}/src/TtZAnalysis/Tools/TUnfold/libunfold.so ${CMSSW_BASE}/external/${SCRAM_ARCH}/lib/libunfold.so
	echo "library symlink set"
    elif [[ !  -a ../FWCore/FWLite/BuildFile.xml  ]]
    then
	mkdir -p ../FWCore
	ln -s $CMSSW_RELEASE_BASE/src/FWCore/FWLite ../FWCore/FWLite
	echo "set up link to  FWCore/FWLite"
    fi
fi
