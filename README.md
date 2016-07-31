Unreal Manifest
=============

UnrealManifest is a manifest file generator for [Unreal Updater](https://github.com/arbonagw/UnrealUpdater). Compile this program and run it inside your project's directory, it will generate a manifest file for Unreal Updater.

	<FolderProperties FolderName=".">
		<Folders>
			<FolderProperties FolderName="FolderA">
				<Folders/>
				<Files>
					<FileProperties FileName="FileA" Size="889416" md5="53406e9988306cbd4537677c5336aba4"/>
					<FileProperties FileName="FileB" Size="45014" md5="54498899854584bd4534584bd336a544"/>
				</Files>
			</FolderProperties>
		</Folders>
		<Files/>
	</FolderProperties>

UnrealUpdater is developped by Gwennaël ARBONA.  
