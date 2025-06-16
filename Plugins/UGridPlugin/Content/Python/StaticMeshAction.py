import unreal 

def set_collision_complexity(asset):
    body_setup = asset.get_editor_property('body_setup')
    collision_trace_flag = unreal.CollisionTraceFlag.CTF_USE_COMPLEX_AS_SIMPLE
    body_setup.set_editor_property('collision_trace_flag', collision_trace_flag)
    asset.set_editor_property('body_setup', body_setup) 

def run():
    assets = unreal.EditorUtilityLibrary.get_selected_assets() 
    unreal.log(assets)

    for asset in assets:
        unreal.log(asset.get_name())
        set_collision_complexity(asset)

run()