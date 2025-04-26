import unreal 

def run():
    actors = unreal.get_editor_subsystem(unreal.EditorActorSubsystem).get_selected_level_actors()

    for actor in actors:
        unreal.log(actor.get_name())
        mats = actor.static_mesh_component.get_materials()
        actor.static_mesh_component.set_editor_property("override_materials",mats)
        

run()