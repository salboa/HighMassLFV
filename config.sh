setupATLAS
localSetupRucioClients
voms-proxy-init -voms atlas
localSetupPandaClient currentJedi --noAthenaCheck
rcSetup
